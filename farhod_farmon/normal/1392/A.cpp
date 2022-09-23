#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 3000010;
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < int > a(n);
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                }
                sort(a.begin(), a.end());
                if(a[0] == a[n - 1]) cout << n << "\n";
                else cout << 1 << "\n";
        }
}