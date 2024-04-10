#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int Q = 1 << 21;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
bool used[N];
vector < int > a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("sum.in", "r", stdin);
        //freopen("sum.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                int k;
                cin >> k;
                a[i].resize(k);
                for(int j = 0; j < k; j++){
                        cin >> a[i][j];
                }
        }

        for(int i = 1; i <= n; i++){
                for(int x: a[i]){
                        used[x] = true;
                }
                for(int j = i + 1; j <= n; j++){
                        bool good = false;
                        for(int x: a[j]){
                                good |= used[x];
                        }
                        if(!good){
                                cout << "impossible" << "\n";
                                return 0;
                        }
                }
                for(int x: a[i]){
                        used[x] = false;
                }
        }
        cout << "possible" << "\n";
}