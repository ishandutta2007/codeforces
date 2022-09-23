#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 100100;
const long long m1 = 1e9 + 3;

using namespace std;

int n;
int m;
int ans[N];
vector < int > v[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
        }
        for(int i = 1; i <= m; i++){
                sort(v[i].begin(), v[i].end());
                reverse(v[i].begin(), v[i].end());
                int s = 0;
                for(int j = 0; j < v[i].size(); j++){
                        s += v[i][j];
                        ans[j + 1] += max(s, 0);
                }
        }
        int best = 0;
        for(int i = 0; i < N; i++){
                best = max(best, ans[i]);
        }
        cout << best << "\n";
}