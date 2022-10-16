#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 
 
 
int t, n;
 
char s[110][110];
int cnt[110];
int bc[110];
 
void solve()
{
    for (scanf("%d", &t); t; t--) {
        memset(cnt,0,sizeof(cnt));
        memset(bc,0,sizeof(bc));
 
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", s[i]);
            int l = strlen(s[i]);
            cnt[l]++;
            for (int j = 0; j < l; j++) bc[s[i][j]-'0']++;
        }
 
        int fp = bc[1]/2 + bc[0]/2;
        int hp = bc[1]%2 + bc[0]%2;
 
        int ans = 0;
        for (int ll = 0; ll <= 50; ll++) {
            for (int k = 0; k < cnt[ll]; k++) {
                int nfp = ll/2;
                int nhp = ll%2;
 
                if (nhp && !hp) {
                    if (!fp) break;
                    fp--;
                    hp += 2;
                }
 
                if (fp >= nfp && hp >= nhp) {
                    fp -= nfp;
                    hp -= nhp;
                    ans++;
                }
            }
        }
 
        printf("%d\n", ans);
    }
}
 
 
#include <fstream>
 
 
int main() {
 
 
    solve();
}