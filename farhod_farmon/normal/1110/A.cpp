#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100010;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int b, k;
        cin >> b >> k;
        b %= 2;
        for(int i = 1; i <= k; i++){
                int x;
                cin >> x;
                x %= 2;
                if(i < k){
                        x &= b;
                }
                n ^= x;
        }
        if(n){
                cout << "odd" << "\n";
        }
        else{
                cout << "even" << "\n";
        }
}