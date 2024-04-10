#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int b[N];
long long F;
long long a[N], f[N];
vector < int > v[N];
vector < int > res, to_add;

void dfs(int x)
{
        for(int y: v[x]){
                dfs(y);
                if(a[y] > 0){
                        a[x] += a[y];
                        res.push_back(y);
                } else{
                        to_add.push_back(y);
                }
        }
        F += a[x];
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                f[i] = a[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> b[i];
                if(b[i] != -1){
                        v[b[i]].push_back(i);
                }
        }
        for(int i = 1; i <= n; i++){
                if(b[i] == -1){
                        dfs(i);
                        res.push_back(i);
                }
        }
        reverse(to_add.begin(), to_add.end());
        for(int x: to_add){
                res.push_back(x);
        }

        cout << F << "\n";
        long long shit = 0;
        for(int x: res){
                shit += f[x];
                if(b[x] != -1){
                        f[b[x]] += f[x];
                }
                cout << x << " ";
        }
        assert(shit == F);
}