#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 300300;
const long long mod = 998244353;

using namespace std;

int n;
int a[N];
int r[N];
map < int, int > used;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = n; i >= 1; i--){
                if(used.find(a[i]) != used.end()){
                        r[i] = used[a[i]];
                }
                used[a[i]] = i;
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
                int j = max(i, r[i]);
                while(i + 1 <= j){
                        i++;
                        j = max(j, r[i]);
                }
                cnt++;
        }
        int res = 1;
        for(int i = 1; i < cnt; i++){
                res += res;
                if(res >= mod){
                        res -= mod;
                }
        }
        cout << res << "\n";
}