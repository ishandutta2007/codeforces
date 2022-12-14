#include <bits/stdc++.h>
//#pragma comment(linker, /STACK:36777216)
            
using namespace std;
            
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
pair<int, int> a[2002];

int getPos[9999 + 1];
int dp[10][2001][715];

void up(int &a, int val){
	a = min(a, val); 
}

int tt[4];

int build(int w1, int w2, int w3, int w4){
	tt[0] = w1;
	tt[1] = w2;
	tt[2] = w3;
	tt[3] = w4;
	sort(tt, tt + 4);
	reverse(tt, tt + 4);
	return getPos[((tt[0] * 10 + tt[1]) * 10 + tt[2]) * 10 + tt[3]];
}	

int main(){	
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;

    vector<int> tmp;
    for (int i1 = 0; i1 <= 9; i1++)
    for (int i2 = 0; i2 <= i1; i2++)
    for (int i3 = 0; i3 <= i2; i3++)
    for (int i4 = 0; i4 <= i3; i4++){
    	int now = ((i1 * 10 + i2) * 10 + i3) * 10 + i4;
    	tmp.pb(now);
    }
    for (int i = 0; i < tmp.size(); i++) getPos[tmp[i]] = i;

    for (int i = 0; i < 10; i++)
    for (int j = 0; j < 2001; j++)
    for (int s = 0; s < 715; s++)
    	dp[i][j][s] = 1e9 + 7;

   	dp[1][0][0] = 0;

   	for (int i = 0; i <= n; i++){
   		for (int mask = 714; mask >= 0; mask--){
   			for (int it = 0; it < 10; it++){
	   			for (int fl = 1; fl < 9; fl++){
	   				up(dp[fl + 1][i][mask], dp[fl][i][mask] + 1);
	   			}
	   			for (int fl = 9; fl >= 2; fl--){
	   				up(dp[fl - 1][i][mask], dp[fl][i][mask] + 1);
	   			}
   			}
   			for (int fl = 1; fl <= 9; fl++){
   				int now = tmp[mask];
   				int w1 = now % 10; now /= 10;
   			 	int w2 = now % 10; now /= 10;
   				int w3 = now % 10; now /= 10;
   				int w4 = now % 10; now /= 10;
   				if (w1 == fl) w1 = 0;
   				if (w2 == fl) w2 = 0;
   				if (w3 == fl) w3 = 0;
   				if (w4 == fl) w4 = 0;
   				int uk = i;
   				if (w1 == 0 && uk < n && a[uk].x == fl) w1 = a[uk].y, uk++;
   				if (w2 == 0 && uk < n && a[uk].x == fl) w2 = a[uk].y, uk++;
   				if (w3 == 0 && uk < n && a[uk].x == fl) w3 = a[uk].y, uk++;
   				if (w4 == 0 && uk < n && a[uk].x == fl) w4 = a[uk].y, uk++; 
   				int newPos = build(w1, w2, w3, w4);	
   				up(dp[fl][uk][newPos], dp[fl][i][mask]);
   			}
   		}
   	}

   	int ans = 2e9 + 7;
   	for (int i = 1; i <= 9; i++) ans = min(ans, dp[i][n][0]);
   	cout << ans + 2 * n;
}