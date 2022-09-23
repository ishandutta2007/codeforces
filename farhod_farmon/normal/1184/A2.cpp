#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 998244353;

using namespace std;

int n;
int a[N];
int s[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        int res = 1;
        for(int i = 1; i <= n; i++){
                char c;
                cin >> c;
                a[i] = c - '0';
                if(a[i]){
                        res = 0;
                }
        }
        for(int i = 1; i < n; i++){
                if(n % i == 0){
                        s[i] = 1;
                        for(int j = 1; j <= i; j++){
                                int shit = 0;
                                for(int h = j; h <= n; h += i){
                                        shit ^= a[h];
                                }
                                if(shit){
                                        s[i] = 0;
                                }
                        }
                }
        }
        for(int i = 1; i < n; i++){
                res += s[__gcd(n, i)];
        }
        cout << res << "\n";
}