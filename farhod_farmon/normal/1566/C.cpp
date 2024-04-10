#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
int d[N];
string s, t;

void solve()
{
        cin >> n >> s >> t;

        int last_0 = -1, last_1 = -1;
        for(int i = 1; i <= n; i++){
                for(char x: {s[i - 1], t[i - 1]}){
                        if(x == '0'){
                                last_0 = i;
                        } else{
                                last_1 = i;
                        }
                }
                d[i] = d[i - 1];
                if(last_0 != -1){
                        d[i] = max(d[i], d[last_0 - 1] + 1);

                        if(last_1 != -1){
                                d[i] = max(d[i], d[min(last_0, last_1) - 1] + 2);
                        }
                }
        }
        cout << d[n] << "\n";
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}