#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
long long a[N];
long long coef[N];
vector < int > v[N];
vector < int > leaf;
long long inf = 2e13;
long long sum;

void dfs(int x, int p)
{
        if(coef[x] > inf){
                cout << sum << "\n";
                exit(0);
        }
        for(int y: v[x]) if(y != p){
                coef[y] = coef[x] * (v[x].size() - (x != p));
                dfs(y, x);
        }
        if(v[x].size() - (x != p) == 0){
                leaf.push_back(x);
        }
}

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);


        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                sum += a[i];
        }
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        coef[1] = 1;
        dfs(1, 1);
        long long L = 1;
        for(int x: leaf){
                L /= __gcd(L, coef[x]);
                if(L > (long long)(1e18) / coef[x]){
                        cout << sum << "\n";
                        return 0;
                }
                L *= coef[x];
        }

        long long l = 0, r = (long long)(1e18) / L;
        while(l < r){
                long long m = (l + r) / 2 + 1;
                bool good = true;
                for(int x: leaf){
                        if(L * m / coef[x] > a[x]){
                                good = false;
                        }
                }
                if(good){
                        l = m;
                } else{
                        r = m - 1;
                }
        }
        cout << sum - L * l << "\n";
}