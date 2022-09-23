#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
const long long mod = 1000000007;
const int MAGIC = 2000;

using namespace std;

int n;
int m;
vector < int > b[N];
vector < int > a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        int x;
                        cin >> x;
                        a[i + j].push_back(x);
                }
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        int x;
                        cin >> x;
                        b[i + j].push_back(x);
                }
        }
        int res = 1;
        for(int i = 1; i < N; i++){
                sort(a[i].begin(), a[i].end());
                sort(b[i].begin(), b[i].end());
                for(int j = 0; j < a[i].size(); j++){
                        if(a[i][j] != b[i][j]){
                                res = 0;
                        }
                }
        }
        cout << (res ? "YES" : "NO") << "\n";
}