#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000100;

using namespace std;

int n;
int a[N];
long long inf = 1e18;

long long solve(int need)
{
        vector<int> c(2, 0);
        long long res = 0;
        for(int i = 1; i <= n; i++){
                if(a[i] == need){
                        need ^= 1;
                        res += c[need];
                        if(c[need] > 0){
                                c[need] -= 1;
                                need ^= 1;
                        }
                } else{
                        c[a[i]] += 1;
                }
        }
        if(c[0] + c[1]){
                return inf;
        }
        return res;
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                cin >> n;
                for(int i = 1; i <= n; i++){
                        cin >> a[i];
                        a[i] %= 2;
                }
                long long res = min(solve(0), solve(1));
                if(res == inf){
                        res = -1;
                }
                cout << res << "\n";
        }
}