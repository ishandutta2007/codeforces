#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 100100;
const long long m1 = 1e9 + 3;

using namespace std;

int n;
int a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        vector < int > v, g;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                if(a[i] == 1){
                        g.push_back(i);
                }
                else{
                        v.push_back(i);
                        a[i] -= 2;
                }
        }
        vector < pair < int, int > > ans;
        for(int i = 0; i + 1 < v.size(); i++){
                ans.push_back({v[i], v[i + 1]});
        }
        if(v.empty()){
                if(n < 3){
                        cout << "YES" << " " << n - 1 << "\n";
                        if(n == 2){
                                cout << 1 << "\n";
                                cout << 1 << " " << 2 << "\n";
                        }
                }
                else{
                        cout << "NO" << "\n";
                }
                return 0;
        }
        for(int i = 0; i < g.size(); i++){
                if(i == 0){
                        ans.push_back({g[i], v[0]});
                }
                else if(i == 1){
                        ans.push_back({g[i], v.back()});
                }
                else{
                        bool gg = true;
                        for(int x: v){
                                if(a[x]){
                                        a[x]--;
                                        gg = false;
                                        ans.push_back({g[i], x});
                                        break;
                                }
                        }
                        if(gg){
                                cout << "NO" << "\n";
                                return 0;
                        }
                }
        }
        int cc = v.size() - 1 + min(2, (int)g.size());
        cout << "YES" << " " << cc << "\n";
        cout << ans.size() << "\n";
        for(auto p: ans){
                cout << p.fi << " " << p.se << "\n";
        }
}