#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100010;

using namespace std;

void solve()
{
        int n;
        cin >> n;
        string s;
        cin >> s;
        int first = n + 1;
        for(int i = 0; i < n; i++){
                if(s[i] == '0'){
                        first = i;
                        break;
                }
        }
        int last;
        for(int i = 0; i < n; i++){
                if(s[i] == '0'){
                        last = i;
                }
        }

        if(n - first > n / 2){
                cout << first + 1 << " " << n << " " << first + 2 << " " << n << "\n";
        } else{
                if(first == n + 1){
                        cout << 1 << " " << n - 1 << " " << 2 << " " << n << "\n";
                } else{
                        cout << 1 << " " << last + 1 << " " << 1 << " " << last << "\n";
                }
        }
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