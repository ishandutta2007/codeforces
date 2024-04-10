#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        vector < int > a(n);
        for(int i = 0; i < n; i++){
                cin >> a[i];
        }
        sort(a.begin(), a.end());
        int res = 0;
        for(int x: a){
                res += x == a[0];
        }
        if(res <= n / 2){
                cout << "Alice" << "\n";
        } else{
                cout << "Bob" << "\n";
        }
}