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

const int N = 50050;

using namespace std;

map < int, vector < int > > v;
map < pair < int, int >, int > used;

int get( string s, int i, int j )
{
    int p = 27, cnt = 0;
    for( int h = 0; h < j; h++ ){
        cnt += (s[i + h] - 'a' + 1) * p;
        p *= 27;
    }
    return cnt + j;
}

int main()
{
    ios_base::sync_with_stdio(0);
    string s;
    int q, i, j, h;
    cin >> s;
    for( i = 0; i < s.size(); i++ ){
        for( j = 1; j <= 4; j++ ){
            v[get(s, i, j)].pb(i);
        }
    }
    cin >> q;
    for( i = 1; i <= q; i++ ){
        string a, b;
        cin >> a >> b;
        int x = get(a, 0, a.size());
        int y = get(b, 0, b.size());
        int ans = 1e9;
        if( used.find(mp(x, y)) != used.end() ){
            cout << used[mp(x, y)] << endl;
            continue;
        }
        if( used.find(mp(y, x)) != used.end() ){
            cout << used[mp(y, x)] << endl;
            continue;
        }
        vector < int > v1 = v[x], v2 = v[y];
        if( v1.empty() || v2.empty() ){
            used[mp(x, y)] = -1;
            cout << -1 << endl;
            continue;
        }
        for( j = 0; j < v1.size(); j++ ){
            h = lower_bound(v2.begin(), v2.end(), v1[j]) - v2.begin();
            if( h >= 0 && h < v2.size() )
                ans = min(ans, max(v1[j] + (int)a.size() - 1, v2[h] + (int)b.size() - 1) - min(v1[j], v2[h]) + 1);
            h--;
            if( h >= 0 && h < v2.size() )
                ans = min(ans, max(v1[j] + (int)a.size() - 1, v2[h] + (int)b.size() - 1) - min(v1[j], v2[h]) + 1);
        }
        if( ans == 1e9 )
            ans = -1;
        used[mp(x, y)] = ans;
        cout << ans << endl;
    }
}