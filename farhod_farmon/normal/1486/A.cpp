#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

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
                long long last = -1, res = 1, fo = 0;
                for(int i = 1; i <= n; i++){
                        long long x;
                        cin >> x;
                        x += fo;
                        if(x <= last){
                                res = 0;
                        }
                        fo = x - last - 1;
                        last = x - fo;
                }
                cout << (res ? "YES" : "NO") << "\n";
        }
}