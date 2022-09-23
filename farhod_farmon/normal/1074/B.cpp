#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
const long long mod = 998244353;

using namespace std;

int n;
int d[N];
bool used[N];
vector < int > v[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                v[i].clear();
                d[i] = 1e9;
                used[i] = false;
        }
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        int k1, k2;
        cin >> k1;
        vector < int > g(k1);
        for(int i = 0; i < k1; i++){
                cin >> g[i];
        }
        int s;
        cin >> k2;
        for(int i = 0; i < k2; i++){
                int x;
                cin >> x;
                used[x] = 1;
                s = x;
        }
        cout << 'B' << " " << s << endl;
        cin >> s;
        queue < int > q;
        q.push(s);
        d[s] = 0;
        while(!q.empty()){
                int x = q.front();
                q.pop();
                for(int y: v[x]){
                        if(d[y] == 1e9){
                                d[y] = d[x] + 1;
                                q.push(y);
                        }
                }
        }
        int h = -1;
        for(int x: g){
                if(h == -1 || d[x] < d[h]){
                        h = x;
                }
        }
        cout << 'A' << " " << h << endl;
        cin >> s;
        if(used[s]){
                cout << 'C' << " " << h << endl;
        }
        else{
                cout << 'C' << " " << -1 << endl;
        }
}

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        int test;
        cin >> test;
        while(test--){
                solve();
        }
}