#include<bits/stdc++.h>

using namespace std;

int p2[100];
const int lg = 59;
const int mod = 998244353;

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

int power (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = mul (p, a);
        a = mul (a, a);
    }
    return p;
}

int fac[2000009], inv[2000009];
void Prec (int lim){fac[0] = inv[0] = 1;for (int i=1; i<=lim; i++)fac[i] = mul (fac[i - 1], i);
inv[lim] = power (fac[lim], mod - 2);for (int i=lim - 1; i>=0; i--)inv[i] = mul (inv[i + 1], i + 1);}
int comb (int N, int K){if (K > N || N < 0 || K < 0) return 0; int ans = mul (fac[N], inv[N - K]);ans = mul (ans, inv[K]);return ans;}

const int maxNodes = 2e6;
int cntNodes = 0, son[maxNodes][2], isFinal[maxNodes];

/*void del(node* q)
{
    for (int i=0; i<2; i++)
        if (q->son[i] != nullptr)
            del(q->son[i]);
    delete q;
}*/

void insertValue(int root, long long val, int minPos)
{
    //printf ("+ %I64d, %d\n", val, minPos);
    if (isFinal[root]) return ;
    for (int i=lg; i>=minPos; i--)
    {
        int bit = (val >> i) & 1;
        if (son[root][bit] == 0)
            son[root][bit] = ++cntNodes;
        root = son[root][bit];
        if (isFinal[root]) return ;
    }
    isFinal[root] = true;
    /*root->isFinal = true;
    for (int i=0; i<2; i++)
    {
        if (root->son[i] != nullptr)
            del(root->son[i]);
        root->son[i] = nullptr;
    }*/
}

int read()
{
    int N, ans = ++cntNodes;
    scanf ("%d", &N);
    while (N --)
    {
        long long l, r, mskL = 0, mskR = 0;
        scanf ("%I64d %I64d", &l, &r);
        l --, r ++; ///l < x < r
        for (int i=lg; i>=0; i--) ///first position where x differs from l, r
        {
            int bitL = (l >> i) & 1, bitR = (r >> i) & 1;
            if (bitL) mskL |= 1LL << i;
            if (bitR) mskR |= 1LL << i;
            if (mskL != mskR && bitL == 0 && mskL + (1LL << i) < mskR)
                insertValue(ans, mskL + (1LL << i), i);
            if (mskL != mskR && bitR == 1 && mskR - (1LL << i) > mskL)
                insertValue(ans, mskR - (1LL << i), i);
        }
    }
    return ans;
}

function<void(long long, int)> toDo;

void dfs(int root, long long val, int i)
{
    if (isFinal[root])
    {
        toDo(val, i);
        return ;
    }
    for (int bit = 0; bit < 2; bit ++)
        if (son[root][bit] != 0)
            dfs(son[root][bit], val + (1LL << i) * bit, i - 1);
}

vector<pair<long long, int>> getVals(int root)
{
    vector<pair<long long, int>> ans;
    toDo = [&ans](long long val, int i) {
        ans.push_back({val, i});
    };
    dfs(root, 0, lg);
    return ans;
}

void print(vector<pair<long long, int>>& curr)
{
    for (auto p : curr)
        printf ("%I64d %d\n", p.first, p.second);
}

int div2(int x)
{
    if(x & 1) x += mod;
    x >>= 1;
    return x;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int t1 = read();
int t2 = read();
vector<pair<long long, int>> x = getVals(t1), y = getVals(t2);
/*print(x);
printf("\n");
print(y);
printf("\n");*/
//del(t1), del(t2);
int root = ++cntNodes;
for (auto &currX : x)
    for (auto &currY : y)
        insertValue(root, currX.first ^ currY.first, max(currX.second, currY.second) + 1);
p2[0] = 1;
for (int i=1; i<=lg; i++)
    p2[i] = add(p2[i - 1], p2[i - 1]);
int ans = 0;
toDo = [&ans](long long val, int i) {
    //printf("%I64d %d\n", val, i);
    i ++;
    /*for (int j=val; j<val + (1LL << i); j++)
        adto(ans, j);*/
    adto(ans, mul(val % mod, p2[i]));
    if (i > 0)
        adto(ans, mul(p2[i - 1], subtract(p2[i], 1)));
};
dfs(root, 0, lg);
printf("%d\n", ans);
return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/