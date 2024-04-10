#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 100100;
const int mod = 998244353;

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
                int n;
                cin >> n;
                cout << "1" << "\n";
                vector < pair < string, int > > v;
                v.push_back({"", 1});
                for(int i = 0; i < n; i++){
                        int x;
                        cin >> x;
                        if(i == 0){
                                assert(x == 1);
                                continue;
                        } else if(x == 1){
                                v.push_back({v.back().fi + to_string(v.back().se) + ".", 0});
                        }
                        while(v.back().se + 1 != x){
                                v.pop_back();
                        }
                        cout << v.back().fi + to_string(x) << "\n";
                        v.back().se += 1;
                }
        }
}