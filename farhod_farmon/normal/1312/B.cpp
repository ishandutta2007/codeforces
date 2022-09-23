#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 30300;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < int > a(n);
                for(int i = 0; i < n; i++) cin >> a[i];
                sort(a.begin(), a.end());
                reverse(a.begin(), a.end());
                for(int x: a)cout << x << " ";
                cout << '\n';
        }
}