#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 200200;
const long long mod = 998244353;

using namespace std;

int n;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        int a = 0, b = 0;
        for(int i = 1; i <= n; i++){
                char c;
                int x, y;
                cin >> c >> x >> y;
                if(x > y){
                        swap(x, y);
                }
                if(c == '+'){
                        a = max(a, x);
                        b = max(b, y);
                }
                else{
                        if(a <= x && b <= y){
                                cout << "YES" << "\n";
                        }
                        else{
                                cout << "NO" << "\n";
                        }
                }
        }
}