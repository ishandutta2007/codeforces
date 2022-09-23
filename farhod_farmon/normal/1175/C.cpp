#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int Q = 10000011;
const int mod = 1e9 + 7;

using namespace std;

int n;
int k;
int a[N];

int get(int m)
{
        int cnt = 0;
        for(int i = 1, j = 1;;){
                if(i <= n && j <= n){
                        if(a[i] - m <= a[j] + m){
                                cnt += 1;
                                i += 1;
                        } else{
                                cnt -= 1;
                                j += 1;
                        }
                } else if(i <= n){
                        cnt += 1;
                        i += 1;
                } else if(j <= n){
                        cnt -= 1;
                        j += 1;
                } else{
                        break;
                }
                if(cnt > k){
                        return max(1, a[i - 1] - m);
                }
        }
        return -1;
}

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        int l = 0, r = 1e9;
        while(l < r){
                int m = (l + r) / 2;
                if(get(m) != -1){
                        r = m;
                } else{
                        l = m + 1;
                }
        }
        cout << get(l) << "\n";
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                solve();
        }
}