#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 600600;
const int mod = 1e9 + 7;

using namespace std;



int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                long long a, b;
                cin >> a >> b;
                long long cnt = 0, x = 9;
                while(x <= b){
                        cnt += 1;
                         x = x * 10 + 9;
                }
                cout << a * cnt << "\n";
        }
}