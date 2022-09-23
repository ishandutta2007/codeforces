#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 111;
const long long mod = 998244353;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n, m, k;
        cin >> n >> m >> k;
        if(min(m, k) < n){
                cout << "No" << "\n";
        } else{
                cout << "Yes" << "\n";
        }
}