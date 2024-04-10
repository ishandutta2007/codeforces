#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 5222;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
bool a[N][N];

bool can(int k)
{
        for(int i = 1; i <= n; i += k){
                for(int j = 1; j <= n; j += k){
                        for(int x = 0; x < k; x++){
                                for(int y = 0; y < k; y++){
                                        if(a[i][j] != a[i + x][j + y]){
                                                return false;
                                        }
                                }
                        }
                }
        }
        return true;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("tracking2.in", "r", stdin);
        //freopen("tracking2.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        int x;
        string s;
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> s;
                for(int j = 0; j < n / 4; j++){
                        if('0' <= s[j] && s[j] <= '9'){
                                x = s[j] - '0';
                        }
                        else{
                                x = s[j] - 'A' + 10;
                        }
                        a[i][j * 4 + 1] = (x >> 3) & 1;
                        a[i][j * 4 + 2] = (x >> 2) & 1;
                        a[i][j * 4 + 3] = (x >> 1) & 1;
                        a[i][j * 4 + 4] = (x >> 0) & 1;
                }
        }
        for(int i = n; i >= 1; i--){
                if(n % i == 0 && can(i)){
                        cout << i << "\n";
                        return 0;
                }
        }
}