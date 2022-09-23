#include <bits/stdc++.h>

#define lli long long int
#define sc scanf
#define pr printf
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

using namespace std;

vector < int > v[10], g;
int n, k, i, j, h, cnt = 0, ans = 1e9, mx, a;
string s, t, ts;

int main()
{
    cin >> n >> k >> s;
    ts = s;
    for( i = 0; i < s.size(); i++ ){
        v[s[i] - '0'].pb(i);
    }
    for( i = 0; i < 10; i++ ){
        g.clear();
        for( j = 1; j < 10; j++ ){
            if( i + j < 10 )g.pb(i + j);
            if( i - j >= 0 )g.pb(i - j);
        }
        a = v[i].size();
        cnt = 0;
        j = 0;
        s = ts;
        while( a < k ){
            int x = g[j];
            j++;
            int g = min(k - a, (int)v[x].size());
            cnt += g * abs(x - i);
            a += g;
            if( x > i ){
                for( h = 0; h < g; h++ )s[v[x][h]] = char(i + '0');
            }
            else{
                for( h = (int)v[x].size() - 1; h >= (int)v[x].size() - g; h-- )s[v[x][h]] = char(i + '0');
            }
        }
        if( cnt < ans ){
            ans = cnt;
            t = s;
        }
        else if( cnt == ans )t = min(t, s);
    }
    cout << ans << endl << t << endl;
}