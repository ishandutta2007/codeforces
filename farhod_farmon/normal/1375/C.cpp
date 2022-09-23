#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 330;
const int mod = 1e9 + 7;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < int > v;
                for(int i = 1; i <= n; i++){
                        int x;
                        cin >> x;
                        if(v.empty() || x < v.back()){
                                v.push_back(x);
                                continue;
                        }
                        while(v.size() > 1 && v.back() < x){
                                v.pop_back();
                        }
                        if(v.back() > x){
                                v.push_back(x);
                        }
                }
                cout << (v.size() == 1 ? "YES" : "NO") << "\n";
        }
}