#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 1010;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                vector < int > a(3);
                cin >> a[0] >> a[1] >> a[2];
                sort(a.begin(), a.end());

                cout << (a[0] + a[1] + 1 < a[2] ? "NO" : "YES") << "\n";
        }
}