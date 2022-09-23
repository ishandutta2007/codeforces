#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
const int Q = 10000011;
const long long mod = 998244353;

using namespace std;

int n;
int a[N];
int b[N];
int c[N];
int d[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                c[a[i]] = i;
        }
        for(int i = 1; i <= n; i++){
                cin >> b[i];
                d[b[i]] = i;
        }
        vector < pair < pair < int, int >, pair < int, int > > > res;
        for(int i = 1; i <= n; i++){
                int j = i;
                int x = c[i], y = d[j];
                if(x == i && y == j){
                        continue;
                }
                res.push_back({{x, j}, {i, y}});
                b[y] = b[j];
                a[x] = a[i];
                c[a[x]] = x;
                d[b[y]] = y;
        }
        cout << res.size() << "\n";
        for(auto p: res){
                cout << p.fi.fi << " " << p.fi.se << ' ' << p.se.fi << " " << p.se.se << "\n";
        }
}