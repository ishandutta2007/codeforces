#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

long long n;
long long p[N];
long long sz[N];
vector < pair < long long, long long > > v;

bool f(long long x)
{
    while(x){
        if(x % 10 != 4 && x % 10 != 7)
            return false;
        x /= 10;
    }
    return true;
}

long long get(long long x)
{
    if(x == p[x])
        return x;
    return p[x] = get(p[x]);
}

bool used[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    if(n < 3){
        cout << 0 << endl;
        return 0;
    }
    long long ans = n * (n - 1) * (n - 2);
    for(int i = 1; i <= n; i++){
        p[i] = i;
        sz[i] = 1;
    }
    for(int i = 1; i < n; i++){
        long long x, y, w;
        cin >> x >> y >> w;
        if(!f(w)){
            x = get(x);
            y = get(y);
            sz[y] += sz[x];
            p[x] = y;
        }
    }
    for(int i = 1; i <= n; i++){
        //if(sz[i] == 1)
        //    continue;
        long long x = get(i);
        if(!used[x]){
            ans -= sz[x] * (sz[x] - 1) * (sz[x] - 2);
        }
        used[x] = true;
        //cout << sz[x] << endl;
        ans -= (n - sz[x]) * (sz[x] - 1) * 2;
    }
    cout << ans << endl;
}