#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1000100;

using namespace std;

int r[N];
bool p[N];
int n;
int a[N];

void dfs(int x, int g)
{
    if(g > n)
        return;
    a[g] = x;
    dfs(r[x], g + 2);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        if(y == 0)
            y = N - 1;
        p[y] = true;
        r[x] = y;
    }
    int h1 = -1,
        h2 = -1;
    for(int i = 0; i < N; i++){
        if(r[i] && !p[i]){
            if(h1 == -1)
                h1 = i;
            else if(h2 == -1)
                h2 = i;
            else
                break;
        }
    }
    dfs(r[h1], 2);
    dfs(h2, 1);
    for(int i = 1; i <= n; i++)
        cout << a[i] << " ";
}