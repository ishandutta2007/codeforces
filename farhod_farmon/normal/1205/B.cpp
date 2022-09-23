#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 1e9 + 7;

using namespace std;

int n;
long long a[N];
vector < int > v[N];
int res = 1e9;
int d[N];

void solve(int x)
{
        queue < int > q;
        q.push(x);
        for(int i = 1; i <= n; i++){
                d[i] = 1e9;
        }
        d[x] = 0;
        while(!q.empty()){
                int x = q.front();
                q.pop();
                for(int y: v[x]){
                        if(d[y] == 1e9){
                                d[y] = d[x] + 1;
                                q.push(y);
                        } else if(d[y] >= d[x]){
                                res = min(res, d[x] + d[y] + 1);
                        }
                }
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        vector < int > c(65, 0);
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                if(a[i] == 0){
                        i -= 1;
                        n -= 1;
                        continue;
                }
                for(int j = 0; j < 62; j++){
                        c[j] += (a[i] >> j) & 1;
                }
        }
        for(int x: c){
                if(x > 2){
                        cout << 3 << "\n";
                        return 0;
                }
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        if(i != j && (a[i] & a[j]) > 0){
                                v[i].push_back(j);
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                solve(i);
        }
        if(res == 1e9){
                res = -1;
        }
        cout << res << "\n";
}