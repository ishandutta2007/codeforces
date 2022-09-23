#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 111;
const int mod = 1e9 + 7;

using namespace std;


int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n;
                long long W;
                cin >> n >> W;
                long long sum = 0;
                set < pair < long long, int > > S;
                int res = -1;
                for(int i = 0; i < n; i++){
                        long long x;
                        cin >> x;
                        if(x > W){
                                continue;
                        } else if(x >= (W + 1) / 2){
                                res = i + 1;
                        } else{
                                S.insert({x, i + 1});
                                sum += x;
                        }
                }
                if(res != -1){
                        cout << 1 << "\n";
                        cout << res << "\n";
                        continue;
                }
                while(sum > W){
                        sum -= S.begin()->fi;
                        S.erase(S.begin());
                }

                if(sum < (W + 1) / 2){
                        cout << -1 << "\n";
                } else{
                        cout << S.size() << "\n";
                        for(auto p: S){
                                cout << p.se << " ";
                        }
                        cout << "\n";
                }
        }
}