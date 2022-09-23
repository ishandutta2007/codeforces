#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int k;
int m;
int a[N];
int c[N];
vector < int > res[N];
vector < int > to_add[N];

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                a[x] += 1;
        }
        for(int i = 1; i <= k; i++){
                cin >> c[i];
        }
        for(int i = k, sum = 0; i >= 1; i--){
                sum += a[i];
                m = max(m, (sum - 1) / c[i] + 1);
        }

        int cur = 0;
        for(int i = k; i >= 1; i--){
                while(a[i]--){
                        res[cur].push_back(i);
                        cur = (cur + 1) % m;
                }
        }
        cout << m << "\n";
        for(int i = 0; i < m; i++){
                cout << res[i].size();
                for(int x: res[i]) cout << " " << x;
                cout << "\n";
        }
}