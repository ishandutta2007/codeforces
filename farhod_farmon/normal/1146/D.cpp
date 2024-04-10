#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 5000200;
const long long mod = 998244353;

using namespace std;

int cnt;
long long res;
bool used[N];
int mx, a, b;
vector < int > v;

void dfs(int x)
{
        v.push_back(x);
        while(!v.empty()){
                x = v.back();
                v.pop_back();
                if(used[x]){
                        continue;
                }
                used[x] = 1;
                cnt += 1;
                if(x + a <= mx){
                        v.push_back(x + a);
                }
                if(x - b >= 0){
                        v.push_back(x - b);
                }
        }
}

long long solve(long long n, long long g)
{
        long long res = (n % g + 1) * (n / g + 1);
        n /= g;
        return res + n * (n + 1) / 2 * g;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        long long n;
        cin >> n >> a >> b;
        used[0] = 1;
        cnt = 1;
        int m = min((long long)5e6, n), g = __gcd(a, b);
        for(int i = 0; i <= m; i++){
                mx = i;
                if(i - a >= 0 && used[i - a]){
                        dfs(i);
                }
                res += cnt;
        }
        if(n > m){
                assert(used[g]);
        }
        res += solve(n, g) - solve(m, g);
        cout << res << "\n";
}