#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        long long res = 0;
        for(int i = 1; i <= n; i++){
                char c;
                cin >> c;
                if(c % 2 == 0){
                        res += i;
                }
        }
        cout << res << "\n";
}