#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 100100;
const long long m1 = 1e9 + 3;

using namespace std;

int n;
char c[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        int gold = 0;
        for(int i = 1; i <= n; i++){
                cin >> c[i];
                gold += c[i] == 'G';
        }
        int ans = 0, cnt = 0;
        for(int i = 1, j = 1; i <= n; i++){
                cnt += c[i] == 'S';
                while(cnt > 1){
                        cnt -= c[j] == 'S';
                        j++;
                }
                int now = i - j + 1 - cnt;
                if(now == gold && cnt > 0){
                        ans = max(ans, i - j);
                }
                else{
                        ans = max(ans, i - j + 1);
                }
        }
        cout << ans << "\n";
}