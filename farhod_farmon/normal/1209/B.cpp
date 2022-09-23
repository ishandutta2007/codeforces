#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 110;

using namespace std;

int n;
int a[N];
int b[N];
int c[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                char x;
                cin >> x;
                c[i] = x - '0';
        }
        for(int i = 1; i <= n; i++){
                cin >> a[i] >> b[i];
        }
        int res = 0;
        for(int i = 0; i < 500000; i++){
                int cnt = 0;
                for(int j = 1; j <= n; j++){
                        if(i >= b[j] && (i - b[j]) % a[j] == 0){
                                c[j] ^= 1;
                        }
                        cnt += c[j];
                }
                res = max(res, cnt);
        }
        cout << res << "\n";
}