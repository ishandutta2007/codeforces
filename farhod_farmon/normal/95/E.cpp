#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

const int N = 100100;

using namespace std;

int n;
int m;
int c[N];
int p[N];
int d[N];
int sz[N];

int get(int x)
{
    if(x == p[x])
        return x;
    return p[x] = get(p[x]);
}

bool lucky(int x)
{
    while(x){
        if(x % 10 != 4 && x % 10 != 7)
            return false;
        x /= 10;
    }
    return true;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        d[i] = 1e9;
        p[i] = i;
    }
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        p[get(x)] = get(y);
    }
    for(int i = 1; i <= n; i++)
        sz[get(i)]++;
    for(int i = 1; i <= n; i++)
        c[sz[i]]++;
    for(int i = 1; i <= n; i++){
        if(c[i] == 0)
            continue;
        for(int p = 1; c[i]; p *= 2){
            p = min(p, c[i]);
            c[i] -= p;
            for(int j = n; j >= p * i; j--)
                d[j] = min(d[j], d[j - p * i] + p);
        }
    }
    int ans = 1e9;
    for(int i = 1; i <= n; i++)
        if(lucky(i))
            ans = min(ans, d[i]);
    if(ans == 1e9)
        ans = 0;
    cout << ans - 1 << endl;
}