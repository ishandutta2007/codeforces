#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 550;
const int MX = 300100;

using namespace std;

int n, m;
int a[N][N];
int nxt[MX];
bool used[MX];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    long long ans = 1e18;
    used[1] = true;
    for(int i = 2; i < MX; i++){
        if(used[i])
            continue;
        for(int j = i + i; j < MX; j += i)
            used[j] = true;
    }
    for(int i = MX - 2; i >= 1; i--){
        if(!used[i])
            nxt[i] = i;
        else
            nxt[i] = nxt[i + 1];
    }
    for(int i = 1; i <= n; i++){
        long long cnt = 0;
        for(int j = 1; j <= m; j++)
            cnt += nxt[a[i][j]] - a[i][j];
        ans = min(ans, cnt);
    }
    for(int i = 1; i <= m; i++){
        long long cnt = 0;
        for(int j = 1; j <= n; j++)
            cnt += nxt[a[j][i]] - a[j][i];
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}