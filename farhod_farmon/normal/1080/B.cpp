#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int Q = 1000100;
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        //freopen("nodes.in","r",stdin);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                int l, r;
                cin >> l >> r;
                int ans = -(r - l + 1) / 2;
                if((r - l + 1) % 2){
                        ans += r;
                }
                if(l % 2){
                        ans = - ans;
                }
                cout << ans << "\n";
        }
}