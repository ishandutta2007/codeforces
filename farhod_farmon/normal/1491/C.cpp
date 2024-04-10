#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 5050;

using namespace std;

int n;
long long a[N];
long long b[N];
long long s[N];
long long d[N];

bool can(long long m)
{
        for(int i = 0; i <= n; i++){
                s[i] = d[i] = 0;
                b[i] = a[i];
        }
        d[1] = m;
        for(int i = 1; i <= n; i++){
                s[i] += s[i - 1];
                d[i] += s[i];

                if(i + b[i] > n){
                        long long g = min(i + b[i] - n, d[i]);
                        d[i] -= g;
                        b[i] -= g;
                        b[i] = max(b[i], 1ll);
                }
                if(!d[i]){
                        continue;
                }

                long long g = min(d[i], b[i] - 1);

                s[i + b[i] - g + 1] += 1;
                s[i + b[i] + 1] -= 1;

                b[i] -= d[i];
                d[i] -= g;

                d[i + 1] += d[i];
        }
        for(int i = 1; i <= n; i++){
                if(b[i] > 1){
                        return false;
                }
        }
        return true;
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        long long l = 0, r = 1e15;
        while(l < r){
                long long m = (l + r) / 2;
                if(can(m)){
                        r = m;
                } else{
                        l = m + 1;
                }
        }
        cout << l << "\n";
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}