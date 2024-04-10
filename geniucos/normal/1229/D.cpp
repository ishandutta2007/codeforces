#include<bits/stdc++.h>

using namespace std;

int nr, N, K, fac[10], comp[130][130], op[200][200], init[200], sz[200];
map < vector < int >, int > mp;
vector < int > perm[1000];
hash<bitset<123>> hash_fn;
struct bitset_compare {
    bool operator() (const bitset<123>& x, const bitset<123>& y) const {
        return hash_fn(x)<hash_fn(y);
    }
};
map < bitset < 123 >, int, bitset_compare > mpG;
bitset < 123 > group[200];
set < bitset < 123 >, bitset_compare > S;

void printBitset (bitset<123> inp, string s)
{
    for (int i=0;i<fac[K];i++)
        if (inp[i])
        {
            printf ("[");
            int needComma = 0;
            for (auto j : perm[i])
            {
                if (needComma)
                    printf (",");
                printf ("%d", j), needComma = 1;
            }
            printf ("]");
        }
    printf ("%s", s.c_str ());
}

void printVectorOfP (vector < int > inp, string s)
{
    for (auto i:inp)
    {
        printf ("[");
        int needComma = 0;
        for (auto j : perm[i])
        {
            if (needComma)
                printf (",");
            printf ("%d", j), needComma = 1;
        }
        printf ("]");
    }
    printf ("%s", s.c_str ());
}

void back (bitset < 123 > curr, vector < int > how)
{
    S.insert (curr);
    group[++nr] = curr, mpG[curr] = nr;

    bool firstStep = 0;
    if (nr == 1)
        firstStep = 1;
//    printBitset (curr, " by "), printVectorOfP(how,"\n");
    for (int i=0; i<fac[K]; i++)
    {
        ///trying to add ith permutation
        bitset < 123 > aux = curr;
        bool ok = 1;
        while (ok)
        {
            ok = 0;
            for (int j=0; j<fac[K]; j++)
                if (aux[j] == 1)
                {
                    int p = comp[j][i];
                    while (aux[p] == 0)
                        aux[p] = 1, p = comp[p][i], ok = 1;
                }
            if (!ok)
            {
                for (int j=0; j<fac[K]; j++)
                    if (aux[j])
                        for (int k=0; k<fac[K]; k++)
                            if (aux[k] == 1&& aux[comp[j][k]] == 0)
                                aux[comp[j][k]] = 1, ok = 1;
            }
        }
        ///maybe it's new
        vector < int > how2=how;how2.push_back(i);
        if (S.find (aux) == S.end ())
            back (aux, how2);
        if (firstStep)
            init[i] = mpG[aux];
    }
}

int combine (bitset<123>x, bitset<123>y)
{
    bitset<123>ans=x|y;
    bool ok = 1;
    while (ok)
    {
        ok = 0;
        for (int i=0; i<fac[K]; i++)
            if (ans[i])
                for (int j=0;j<fac[K];j++)
                    if (ans[j] == 1 && ans[comp[i][j]] == 0)
                        ans[comp[i][j]] = 1, ok = 1;
    }
    return mpG[ans];
}

void init5();

void initialize ()
{
    vector < int > curr;
    for (int i=1; i<=K; i++)
        curr.push_back (i);
    int id = 0;
    do {
        mp[curr] = id, perm[id] = curr, id ++;
    }while (next_permutation (curr.begin (), curr.end ()));
    for (int i=0; i<fac[K]; i++)
        for (int j=0; j<fac[K]; j++)
        {
            vector < int > curr3;
            for (int k=0; k<K; k++)
                curr3.push_back (perm[i][perm[j][k] - 1]);
            comp[i][j] = mp[curr3];
        }
    bitset < 123 > curr2;
    curr2[0] = 1;
    back (curr2, {});
//    printf ("%d\n", S.size ());
/*    for (auto b:S)
        printBitset(b,"\n");*/
    for (int i=1; i<=nr; i++)
        for (int j=i; j<=nr; j++)
            op[i][j] = op[j][i] = combine (group[i], group[j]);
    for (int i=1; i<=nr; i++)
        sz[i] = group[i].count ();
}

int lg[200009], rmq[20][200009];
int query (int i, int j)
{
    int p = lg[j - i + 1];
    return op[rmq[p][i]][rmq[p][j - (1 << p) + 1]];
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K);
fac[0] = 1;
for (int i=1; i<=K; i++)
    fac[i] = fac[i - 1] * i;
initialize ();
for (int i=1; i<=N; i++)
{
    vector < int > curr (K, 0);
    for (int j=0; j<K; j++)
        scanf ("%d", &curr[j]);
    rmq[0][i] = init[mp[curr]];
}
lg[1] = 0;
for (int i=2; i<=N; i++)
{
    lg[i] = lg[i - 1];
    if ((2 << lg[i]) <= i)
        lg[i] ++;
}
for (int i=1; i<=lg[N]; i++)
    for (int j=1; j + (1 << i) - 1<=N; j++)
        rmq[i][j] = op[rmq[i - 1][j]][rmq[i - 1][j + (1 << (i - 1))]];
long long ans = 0;
for (int i=1; i<=N; i++)
{
    int j = i, curr = rmq[0][i], lastConsidered = i - 1;
    while (1)
    {
        int p = j, u = N;
        while (p <= u)
        {
            int mij = (p + u) >> 1;
            if (query (i, mij) == curr) j = mij, p = mij + 1;
            else u = mij - 1;
        }
        ///for all right ends between [lastConsidered + 1, j] it's curr
        ans += 1LL * sz[curr] * (j - lastConsidered);
        lastConsidered = j;
        if (j == N)
            break;
        j ++, curr = op[curr][rmq[0][j]];
    }
}
printf ("%I64d\n", ans);
return 0;
}


void init5()
{

}