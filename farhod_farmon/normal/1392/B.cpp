#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 3000010;
const long long mod = 1e9 + 7;

using namespace std;

void apply(vector < long long > &v)
{
        long long mx = v[0];
        for(auto x: v) mx = max(mx, x);
        for(auto &x: v) x = mx - x;
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n;
                long long k;
                cin >> n >> k;
                vector < long long > a(n);
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                }
                k -= 1;
                apply(a);
                if(k % 2){
                        apply(a);
                }
                for(auto x: a) cout << x << " ";
                cout << "\n";
        }
}