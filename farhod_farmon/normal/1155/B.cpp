#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const long long mod = 998244353;

using namespace std;

int n;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        int cnt = 0;
        for(int i = 1; i <= n - 10; i++){
                char c;
                cin >> c;

                cnt += c == '8' ? 1 : -1;
        }

        if(cnt > 0){
                cout << "YES" << "\n";
        } else{
                cout << "NO" << "\n";
        }
}