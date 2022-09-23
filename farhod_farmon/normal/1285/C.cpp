#include <bits/stdc++.h>
 
#define fi first
#define se second
 
const int N = 110;
 
using namespace std;
 
int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
 
        ios_base::sync_with_stdio(0);
 
        long long X;
        cin >> X;
                pair < long long, long long > res = {1e18, 1e18};
        for(long long a = min(X, (long long)1e6); a >= 1; a--){
                long long g = a / __gcd(X, a);
                long long b = X / (a / g);
 
                if(a * b / __gcd(a, b) == X){
                        if(make_pair(max(a, b), min(a, b)) < res){
                                res = make_pair(max(a, b), min(a, b));
                        }
                }
        }
        cout << res.fi << " " << res.se << "\n";
 
}