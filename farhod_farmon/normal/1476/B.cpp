#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const int mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

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
                long long l = 0, r = 1e15;
                while(l < r){
                        long long m = (l + r) / 2;
                        bool good = true;
                        a[0] += m;
                        long long s = a[0];
                        for(int i = 1; i < n; i++){
                                if(s * k < a[i] * 100){
                                        good = false;
                                        break;
                                }
                                s += a[i];
                        }
                        a[0] -= m;
                        if(good){
                                r = m;
                        } else{
                                l = m + 1;
                        }
                }
                cout << l << "\n";
        }
}