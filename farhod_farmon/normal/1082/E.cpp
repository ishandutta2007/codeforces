#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 500500;
const long long m1 = 1e9 + 3;

using namespace std;

int n;
int k;
int a[N];
int l[N];
int r[N];
vector < int > v[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                v[a[i]].push_back(i);
        }
        for(int i = 1; i <= n; i++){
                l[i] = l[i - 1] + (a[i] == k);
        }
        for(int i = n; i >= 1; i--){
                r[i] = r[i + 1] + (a[i] == k);
        }
        int ans = r[n];
        for(int i = 1; i < N; i++){
                int mx = -1e9;
                for(int j = 0; j < v[i].size(); j++){
                        mx = max(mx, l[v[i][j] - 1] - j);
                        ans = max(ans, mx + r[v[i][j] + 1] + j + 1);
                }
        }
        cout << ans << "\n";
}