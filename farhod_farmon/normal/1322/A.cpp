#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 200200;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int n;
        string s;
        cin >> n >> s;
        int res = 0, last = -1, bal = 0;
        for(int i = 0; i < n; i++){
                int cur = (s[i] == '(' ? 1 : -1);
                if(bal == -1 && bal + cur == 0){
                        res += i - last;
                }
                bal += cur;
                if(bal == 0){
                        last = i;
                }
        }
        if(bal) res = -1;
        cout << res << "\n";
}