#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const long long mod = 998244353;

using namespace std;

int n;
char c[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> c[i];
                if(i > 1 && c[i] < c[i - 1]){
                        cout << "YES" << "\n";
                        cout << i - 1 << " " << i << "\n";
                        return 0;
                }
        }
        cout << "NO" << "\n";
}