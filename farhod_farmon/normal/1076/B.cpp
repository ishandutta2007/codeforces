#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const long long mod = 998244353;

using namespace std;


int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        long long n;
        cin >> n;
        for(long long i = 2; i * i <= n; i++){
                if(n % i == 0){
                        cout << (n - i) / 2 + 1 << "\n";
                        return 0;
                }
        }
        cout << 1 << "\n";
}