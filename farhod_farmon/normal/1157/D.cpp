#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 998244353;

using namespace std;

int n;
int k;
int a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        for(int i = 1; i <= k; i++){
                a[i] = i;
                n -= i;
                if(n < 0){
                        cout << "NO" << "\n";
                        return 0;
                }
        }
        for(int i = 1; i <= k; i++){
                a[i] += n / k;
        }
        n %= k;
        for(int i = 2; i <= k; i++){
                while(k - i + 1 <= n && a[i - 1] * 2 > a[i]){
                        for(int j = i; j <= k; j++){
                                a[j] += 1;
                                n -= 1;
                        }
                }
        }
        if(n){
                cout << "NO" << "\n";
        } else{
                cout << "YES" << "\n";
                for(int i = 1; i <= k; i++){
                        cout << a[i] << " ";
                }
        }
}