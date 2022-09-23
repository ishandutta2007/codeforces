#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 400200;
const int Q = 400200;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                int n;
                cin >> n;
                vector < int > a(n), b(n);
                for(int i = 0; i < n; i++) cin >> a[i];
                for(int i = 0; i < n; i++) cin >> b[i];
                sort(a.begin(), a.end());
                sort(b.begin(), b.end());
                for(int x: a)cout << x << " ";
                cout << "\n";
                for(int x: b)cout << x << " ";
                cout << "\n";
        }
}