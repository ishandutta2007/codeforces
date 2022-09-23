#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int MAGIC = 777;
const int Q = 1 << 21;
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n, k;
        cin >> n >> k;
        k = (n - k) / 2 + 1;
        for(int i = 0; i < n; i++){
                if(i % k == k - 1){
                        cout << 1;
                } else{
                        cout << 0;
                }
        }
}