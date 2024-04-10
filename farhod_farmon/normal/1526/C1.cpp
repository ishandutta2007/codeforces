#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 1000011;
const int mod = 998244353;

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        long long s = 0;
        multiset < int > S;
        for(int i = 0; i < n; i++){
                int x;
                cin >> x;
                s += x;
                S.insert(x);
                while(s < 0){
                        s -= *S.begin();
                        S.erase(S.begin());
                }
        }
        cout << S.size() << "\n";
}