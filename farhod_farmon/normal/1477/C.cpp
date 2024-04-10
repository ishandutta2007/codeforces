#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000010;
const int mod = 1e9 + 7;

using namespace std;

int n;
long long x[N], y[N];
bool used[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> x[i] >> y[i];
        }
        int st = 1;
        for(int i = 1; i <= n; i++){
                cout << st << " ";
                if(i == n){
                        break;
                }
                used[st] = true;
                long long best = -1, h = 0, cur;
                for(int j = 1; j <= n; j++) if(!used[j]){
                        cur = (x[j] - x[st]) * (x[j] - x[st]);
                        cur += (y[j] - y[st]) * (y[j] - y[st]);
                        if(cur > best){
                                best = cur;
                                h = j;
                        }
                }
                st = h;
        }
}