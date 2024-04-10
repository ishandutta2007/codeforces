#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000001;

using namespace std;

int n;
int p[N];
char c[N];
bool good[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        good[0] = true;
        for(int i = 1; i <= n; i++){
                cin >> c[i];
                p[i] = p[i - 1] + (c[i] == '(' ? 1 : -1);
                good[i] = good[i - 1];
                if(p[i] < 0){
                        good[i] = false;
                }
        }
        int res = 0;
        int gg = 1e9;
        for(int i = n; i >= 1; i--){
                gg = min(gg, p[i]);
                if(good[i - 1] == false){
                        continue;
                }
                int dif = (c[i] == '(' ? -2 : 2);
                if(p[n] + dif == 0 && gg + dif >= 0){
                        res += 1;
                }
        }
        cout << res << "\n";
}