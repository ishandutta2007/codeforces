#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 18;

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
                vector < int > a(n, 0);
                int A = 0, B = 0;
                for(int i = 0; i < n; i++){
                        char c;
                        cin >> c;
                        if(c == '>'){
                                A = 1;
                        } else if(c == '<'){
                                B = 1;
                        } else{
                                a[i] = 1;
                                a[(i + 1) % n] = 1;
                        }
                }
                if(A + B != 2){
                        cout << n << "\n";
                        continue;
                }
                int res = 0;
                for(int x: a) res += x;
                cout << res << "\n";
        }
}