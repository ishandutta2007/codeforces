#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const int mod = 1e9 + 7;

using namespace std;


int main()
{
        //freopen("input.txt", "r", stdin);
       // freopen("output.txt", "w", stdout);

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
                int res = 0;
                for(int i= 1; i < n; i++){
                        res |= (a[i] == a[i - 1]);
                }
                cout << (res ? "YES" : "NO") << "\n";
        }
}