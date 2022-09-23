#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const int Q = 1 << 21;
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("sum.in", "r", stdin);
        //freopen("sum.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        int k;
        string s = "aeiou";

        cin >> k;
        for(int i = 5; i <= k; i++){
                int j = k / i;
                if(j >= 5 && i * j == k){
                        for(int x = 0; x < i; x++){
                                for(int y = 0; y < j; y++){
                                        cout << s[(x + y) % 5];
                                }
                        }
                        return 0;
                }
        }
        cout << -1 << "\n";
}