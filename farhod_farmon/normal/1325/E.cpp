#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long
#define dl double long

using namespace std;

const int N = 1e6 + 7;
const long long mod = 1e9 + 7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen( "input.txt" , "r" , stdin );
    //freopen( "output.txt" , "w" , stdout );

    int n;
    cin >> n;
    vector < int > p;
    vector < vector < pair < int , int > > > g(N);
    vector < int > a(N , 0);
    for( int i = 2; i <= 1000; i++ ){
        if( !a[i] ){
            p.push_back(i);
            for( int j = i * i; j <= 1000; j += i ){
                a[j] = 1;
            }
        }
    }
    int G = 0;
    vector < int > np;

    vector < int > C(N, 0);

    for( int i = 1; i <= n; i++ ){
        int x;
        cin >> x;
        vector < int > f;
        for( auto y : p ){
            int cnt = 0;
            while( x % y == 0 ){
                x /= y;
                cnt++;
            }
            if( cnt % 2 )f.push_back(y);
        }
        if(x > 1){
                f.push_back(x);
        }
        if( f.empty() ){
            cout << 1;
            return 0;
        }
        while( (int)f.size() < 2 )f.push_back(1);
        g[f[0]].push_back({f[1] , ++G});
        g[f[1]].push_back({f[0] , G});

        C[f[0] * f[1]] += 1;
        //cout << f[0] << " " << f[1] << "\n";
    }

    for(int x: C){
        if(x > 1){
            cout << 2 << "\n";
            return 0;
        }
    }

    int inf = 1e9;
    int ans = inf;
    vector < int > d( N , inf );
    vector < int > pa( N , inf );
    vector < int > f;
    queue < int > q;
    vector < int > chec( N , 0 );
    for( auto x : p ){
        for( auto y : f ){
            d[y] = pa[y] = inf;
        }
        f.clear();
        d[x] = 0;
        f.push_back(x);
        q.push(x);
        //cout << x << " -> ";
        while( !q.empty() ){
            int xx = q.front();
            q.pop();
            for( auto z : g[xx] ){
                int y = z.fi;
                if( d[y] == inf ){
                    d[y] = d[xx] + 1;
                    pa[y] = z.se;
                    q.push(y);
                    f.push_back(y);
                }else{
                    if( z.se == pa[xx] )continue;
                    ans = min( ans , d[y] + d[xx] + 1 );
                    //cout << y << " " << d[y] << " " << xx << " " << d[xx] << " | ";
                }
            }
        }
        //cout << "\n";
    }
    if( ans == inf )ans = -1;
    cout << ans;
}