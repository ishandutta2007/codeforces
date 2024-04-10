#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 100100;
const int Q = 250200;
const long long mod = 998244353;

using namespace std;

int n;
int m;
int used[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        int res = n;
        for(int i = 1; i <= m; i++){
                int x;
                cin >> x;
                if(!used[x]){
                        res -= 1;
                }
                used[x] += 1;
                if(res == 0){
                        cout << 1;
                        for(int j = 1; j <= n; j++){
                                used[j] -= 1;
                                res += used[j] == 0;
                        }
                }
                else{
                        cout << 0;
                }
        }
}