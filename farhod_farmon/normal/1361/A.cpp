#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;

using namespace std;

int n;
int m;
int c[N];
vector < int > v[N];
vector < int > g[N];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> m;
        for(int i = 1, x, y; i <= m; i++){
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        for(int i = 1, x; i <= n; i++){
                cin >> x;
                g[x].push_back(i);
        }
        vector < int > res;
        set < int > s;
        for(int i = 1; i <= n; i++){
                for(int x: g[i]){
                        res.push_back(x);

                        s.clear();
                        for(int y: v[x]){
                                s.insert(c[y]);
                        }
                        int cur = 1;
                        while(s.find(cur) != s.end()){
                                cur += 1;
                        }
                        if(cur != i){
                                cout << -1 << "\n";
                                return 0;
                        }
                        c[x] = cur;
                }
        }
        for(int x: res){
                cout << x << " ";
        }
}