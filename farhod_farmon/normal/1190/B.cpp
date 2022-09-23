#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 150100;
const long long mod = 998244353;

using namespace std;

int n;
int a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        a[0] = -1;
        int shit = 0;
        int res = (a[n] - n + 1) % 2;
        for(int i = 1; i < n; i++){
                if(a[i] == a[i + 1] && a[i - 1] >= a[i] - 1){
                        cout << "cslnb" << "\n";
                        return 0;
                }
                shit += a[i] == a[i + 1];
                res ^= (a[i] - i + 1) % 2;
        }
        if(!res || shit > 1){
                cout << "cslnb" << "\n";
        } else{
                cout << "sjfnb" << "\n";
        }
}