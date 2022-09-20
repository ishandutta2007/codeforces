#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 300200;

int n;
int a[N];
int c[N];
int id[N];
int dip[N];
int res[N];
int par[N];
vector < int > v[N];
int tin[N], tout[N], tim;

void dfs(int x)
{
        tin[x] = ++tim;
        for(int y: v[x]){
                dip[y] = dip[x] + 1;
                dfs(y);
        }
        tout[x] = ++tim;
}

bool isp(int x, int y)
{
        return tin[x] <= tin[y] && tout[x] >= tout[y];
}

int num;

void trace(int x)
{
        num += 1;
        if(res[x] != num){
                cout << "NO" << "\n";
                exit(0);
        }
        for(int y: v[x]){
                trace(y);
        }
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                id[a[i]] = i;
        }
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                par[y] = x;
                c[x] += 1;
        }

        dfs(1);
        res[1] = 1;

        int r = 1, X = 1;

        long long sum = 0;
        for(int i = 1; i < a[1]; i++){
                int x = id[i];
                sum += dip[x];

                if(!isp(X, x)){
                        if(i + 1 < a[1]){
                                cout << "NO" << "\n";
                                return 0;
                        } else if(!isp(x, X)){
                                cout << "NO" << "\n";
                                return 0;
                        }
                        while(X != x){
                                if(a[X] != r){
                                        cout << "NO" << "\n";
                                        return 0;
                                }
                                r -= 1;
                                X = par[X];
                        }
                } else{
                        int y = x;
                        vector < int > shit;
                        while(y != X){
                                shit.push_back(y);
                                y = par[y];
                        }
                        r += shit.size();
                        for(int j = 0; j < shit.size(); j++){
                                res[shit[j]] = r - j;
                        }
                        X = x;
                }

                X = par[X];
        }

        int x = X;
        while(x){
                if(a[x] != r){
                        cout << "NO" << "\n";
                        return 0;
                }
                r -= 1;
                x = par[x];
        }

        for(int i = 1; i <= n; i++){
                if(!res[i]){
                        res[i] = a[i];
                }
        }

        for(int i = 1; i <= n; i++){
                sort(v[i].begin(), v[i].end(), [&](int x, int y){ return res[x] < res[y]; });
        }

        trace(1);

        cout << "YES\n" << sum << "\n";
        for(int i = 1; i <= n; i++){
                cout << res[i] << " ";
        }
}