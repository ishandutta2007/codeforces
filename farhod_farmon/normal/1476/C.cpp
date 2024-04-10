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
                cin >> n;
                vector < int > a(n), b(n), c(n);
                for(int i = 0; i < n; i++) cin >> c[i];
                for(int i = 0; i < n; i++) cin >> a[i];
                for(int i = 0; i < n; i++){
                        cin >> b[i];
                        if(a[i] > b[i]){
                                swap(a[i], b[i]);
                        }
                }

                long long res = 0;
                set < pair < long long, int > > S;
                vector < long long > s(n, 0);
                for(int i = 1, j = 0; i < n; i++){
                        S.insert({b[i] - a[i] - s[i - 1] - 2 * (i - 1), i - 1});

                        if(a[i] == b[i]){
                                while(j + 1 < i){
                                        S.erase({b[j + 1] - a[j + 1] - s[j] - 2 * j, j});
                                        j += 1;
                                }
                        }

                        res = max(res, (--S.end())->fi + c[i] - 1 + s[i - 1] + 2 * i);
                        //cout << i << " " << res << " " << j << "\n";
                        s[i] = s[i - 1];
                        if(i + 1 < n){
                                s[i] += a[i + 1] - 1 + c[i] - b[i + 1];
                        }
                }

                cout << res << "\n";
        }
}