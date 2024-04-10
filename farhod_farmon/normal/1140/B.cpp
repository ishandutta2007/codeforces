#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                cin >> n;
                for(int i = 1; i <= n; i++){
                        char c;
                        cin >> c;
                        if(c == '>'){
                                a[i] = 1;
                        } else{
                                a[i] = 0;
                        }
                }
                int c = n, d = n;
                for(int i = 1; i <= n; i++){
                        if(a[i] == 1){
                                c = i - 1;
                                break;
                        }
                }
                for(int i = n; i >= 1; i--){
                        if(a[i] == 0){
                                d = n - i;
                                break;
                        }
                }
                cout << min(c, d) << "\n";
        }
}