#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 2020;

using namespace std;


int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int T;
        cin >> T;
        while(T--){
                int n;
                cin >> n;
                vector < int > a(n);
                vector < long long > d;
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                        if(i > 0){
                                d.push_back(a[i] - a[i - 1]);
                        }
                }
                n = d.size();
                long long shit = 0, far = 0, s = 0;
                for(auto x: d){
                        s += x;
                        shit = min(shit, s - far);
                        far = max(far, s);
                }
                shit = - shit;
                long long res = 0;
                while(shit > 0){
                        shit -= (1ll << res);
                        res += 1;
                }
                cout << res << "\n";
        }
}