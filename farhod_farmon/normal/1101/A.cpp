#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 1010;
const long long mod = 998244353;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int q;
        cin >> q;
        for(int i = 0; i < q; i++){
                int l, r, d;
                cin >> l >> r >> d;
                if(d < l){
                        cout << d << "\n";
                }
                else{
                        cout << (r / d + 1) * d << "\n";
                }
        }
}