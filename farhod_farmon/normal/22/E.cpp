#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <iomanip>

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

const int N = 101101;

using namespace std;

bool used[N], lol[N];
int n, p[N], end[N];
vector < int > ans;

void dfs( int x )
{
    if( used[x] ){
        end[x] = x;
        return;
    }
    used[x] = true;
    dfs(p[x]);
    end[x] = end[p[x]];
}

int main()
{
    int i, j, h, x;
    cin >> n;
    for( i = 1; i <= n; i++ ){
        cin >> x;
        p[i] = x;
        lol[x] = true;
    }
    for( i = 1; i <= n; i++ ){
        if( !lol[i] ){
            dfs(i);
            ans.pb(i);
        }
    }
    for( i = 1; i <= n; i++ ){
        if( !used[i] ){
            dfs(i);
            ans.pb(i);
        }
    }
    if( ans.size() == 1 && end[ans[0]] == ans[0] ){
        cout << 0 << endl;
        return 0;
    }
    cout << ans.size() << endl;
    for( i = 0; i < ans.size(); i++ )cout << end[ans[(i + 1) % ans.size()]] << " " << ans[i] << endl;
}