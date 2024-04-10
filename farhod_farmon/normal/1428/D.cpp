#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
int a[N];
vector < int > A[N];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        vector < int > v, g;
        for(int i = n; i >= 1; i--){
                if(a[i] == 0){
                        continue;
                }
                A[i].push_back(i);
                if(a[i] == 1){
                        v.push_back(i);
                        continue;
                }
                int j = -1;
                if(a[i] == 2){
                        if(!v.empty()){
                                j = v.back();
                                v.pop_back();
                                A[j].pop_back();
                        }
                } else{
                        if(!g.empty()){
                                j = g.back();
                                g.pop_back();
                        } else if(!v.empty()){
                                j = v.back();
                                v.pop_back();
                        }
                }
                if(j == -1){
                        cout << -1 << "\n";
                        return 0;
                }
                A[j].push_back(i);
                g.push_back(i);
        }
        vector < pair < int, int > > res;
        for(int i = 1; i <= n; i++){
                for(int j: A[i]){
                        res.push_back({j, i});
                }
        }
        cout << res.size() << "\n";
        for(auto p: res) cout << p.fi << " " << p.se << "\n";
}