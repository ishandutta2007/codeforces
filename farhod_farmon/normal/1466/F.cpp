#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const int mod = 1e9 + 7;

using namespace std;

int n, m;
int p[N];
vector < int > res;

int get(int x) { return p[x] == x ? x : p[x] = get(p[x]); }

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 0; i <= m; i++){
                p[i] = i;
        }
        for(int i = 1; i <= n; i++){
                int k;
                cin >> k;
                int x, y;
                if(k == 1){
                        cin >> y;
                        x = 0;
                } else{
                        cin >> x >> y;
                }
                x = get(x);
                y = get(y);
                if(x == y){
                        continue;
                }
                res.push_back(i);
                p[x] = y;
        }

        int shit = 1;
        for(int i = 0; i < res.size(); i++){
                shit = shit * 2ll % mod;
        }
        sort(res.begin(), res.end());
        cout << shit << " " << res.size() << "\n";
        for(int x: res){
                cout << x << " ";
        }
}