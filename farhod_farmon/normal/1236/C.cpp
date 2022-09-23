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
        for(int i = 1; i <= n; i++){
                int s = 0;
                for(int j = 1; j <= n; j++){
                        if(j & 1){
                                cout << s + i << " ";
                        } else{
                                cout << s + n - i + 1 << " ";
                        }
                        s += n;
                }
                cout << "\n";
        }
}