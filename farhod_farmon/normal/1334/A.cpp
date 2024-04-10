#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 50005;

using namespace std;


int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int T;
        cin >> T;
        while(T--){
                int n;
                bool good = true;

                cin >> n;
                int A = 0, B = 0;
                for(int i = 1; i <= n; i++){
                        int a, b;
                        cin >> a >> b;
                        if(a < A || b < B || a - A < b - B){
                                good = false;
                        }
                        A = a;
                        B = b;
                }

                cout << (good ? "YES" : "NO") << "\n";
        }
}