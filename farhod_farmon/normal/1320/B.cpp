#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int d[N];
vector < int > v[N];
vector < int > g[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int m;
        cin >> n >> m;
        for(int i = 1, x, y; i <= m; i++){
                cin >> x >> y;
                v[y].push_back(x);
                g[x].push_back(y);
        }
        int k;
        cin >> k;
        vector < int > ord(k);
        for(int i = 0; i < k; i++){
                cin >> ord[i];
        }
        queue < int > q;
        q.push(ord[k - 1]);
        d[ord[k - 1]] = 1;
        while(!q.empty()){
                int x = q.front();
                q.pop();
                for(int y: v[x]){
                        if(d[y] == 0){
                                d[y] = d[x] + 1;
                                q.push(y);
                        }
                }
        }
        int A = 0, B = 0;
        for(int i = 0; i < k - 1; i++){
                int x = ord[i], y = ord[i + 1];
                bool good = false;
                for(int z: g[x]){
                        if(d[x] == d[z] + 1 && z != y){
                                good = true;
                        }
                }
                if(good){
                        B += 1;
                }
                if(d[y] + 1 != d[x]){
                        A += 1;
                }
        }
        cout << A << " " << B << "\n";
}