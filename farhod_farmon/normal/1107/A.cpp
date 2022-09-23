#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 10010;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("tracking2.in", "r", stdin);
        //freopen("tracking2.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                int n;
                string s;
                cin >> n >> s;
                if(n == 2 && s[0] >= s[1]){
                        cout << "NO" << "\n";
                }
                else{
                        cout << "YES" << "\n";
                        cout << 2 << "\n";
                        cout << s[0] << " ";
                        for(int i = 1; i < n; i++){
                                cout << s[i];
                        }
                        cout << "\n";
                }
        }
}