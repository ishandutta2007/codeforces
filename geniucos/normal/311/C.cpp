#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int N, M, K, C[100009], ap[100009];
long long Pos[100009], H;

priority_queue < pair < int , int > > PQ;

class graph
{
    public:
    int N;
    long long best[10009];
    vector < pair < int , long long > > v[10009];

    void add_edge (int x, int y, long long c)
    {
        v[x].push_back (make_pair (y, c));
    }

    void solve (int S)
    {
        priority_queue < pair < long long , int > , vector < pair < long long , int > > , greater < pair < long long , int > > > heap;
        for (int i=1; i<=N; i++)
            best[i] = H + 1;
        heap.push (make_pair (1, S));
        while (!heap.empty())
        {
            pair < long long , int > X = heap.top();
            heap.pop();
            if (best[X.second] != H + 1)
                continue;
            best[X.second] = X.first;
            for (vector < pair < int , long long > > :: iterator it = v[X.second].begin(); it != v[X.second].end(); it++)
                if (best[X.second] + it->second < best[it->first])
                    heap.push (make_pair (best[X.second] + it->second, it->first));
        }
    }
}dinamica;

void Refresh ()
{
    dinamica . solve ( 2 ) ;
    for (int i=1; i<=N; i++)
    {
        if (dinamica . best [ Pos[i] % K + 1] <= Pos [ i ] && ap[i] == 0)
            PQ.push ( make_pair (C[i], -i) ), ap[i] = 1;
    }
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%I64d %d %d %d", &H, &N, &M, &K);
for (int i=1; i<=N; i++)
    scanf ("%I64d %d", &Pos[i], &C[i]);

dinamica.N = K;
Refresh ();
while (M)
{
    M --;
    int tip;
    scanf ("%d", &tip);
    if (tip == 1)
    {
        long long X;
        scanf ("%I64d", &X);
        for (int i=0; i<K; i++)
            dinamica.add_edge (i + 1, ((long long)i + X) % K + 1, X);
        Refresh ();
    }
    else
    if (tip == 2)
    {
        int X, Y;
        scanf ("%d %d", &X, &Y);
        C[X] -= Y;
        if (ap[X] == 1)
            PQ.push ( make_pair (C[X], -X));
    }
    else
    {
        int answer, where = -1;
        while (!PQ.empty())
        {
            pair < int , int > curr = PQ.top();
            PQ.pop();
            if (ap[-curr.second] == -1 || C[-curr.second] != curr.first) continue;
            answer = curr.first;
            where = -curr.second;
            break;
        }
        if (where == -1) printf ("0\n");
        else ap[where] = -1, printf ("%d\n", answer);
    }
}

return 0;
}