#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int k;
char c[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("tracking2.in", "r", stdin);
        //freopen("tracking2.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> c[i];
        }
        int res = 0;
        for(int x = 'a'; x <= 'z'; x++){
                int cnt = 0, g = 0;
                for(int i = 1; i <= n; i++){
                        if(c[i] == x){
                                g += 1;
                        }
                        else{
                                g = 0;
                        }
                        if(g == k){
                                cnt += 1;
                                g = 0;
                        }
                }
                res = max(res, cnt);
        }
        cout << res << "\n";
}