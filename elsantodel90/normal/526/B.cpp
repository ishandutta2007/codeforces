#include <iostream>
#include <cmath>

#define forn(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

const int MAXN = 65536;

int v[MAXN];
int n;

struct Info
{
    int added, total;
    Info() {}
    Info(int a, int t) {added = a; total = t;}
};

Info minimum(int node)
{
    if (node >= (1<<n))
        return Info(0, v[node]);
    else
    {
        int c1 = 2*node, c2 = 2*node+1;
        Info a = minimum(c1), b = minimum(c2);
        return Info(a.added + b.added + abs(a.total - b.total), 
                    max(a.total, b.total) + v[node]
                   );
    }
}

int main()
{
    cin >> n;
    v[0] = v[1] = 0;
    forn(i, (1<<(n+1))-2)
        cin >> v[i+2];
    cout << minimum(1).added << endl;
    return 0;
}