#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

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
                int x;
                cin >> x;
                a[x] = 1;
        }
        int res = 0;
        for(int i = 1; i <= 100; i++){
                if(a[i]){
                        res += 1;
                        for(int j = i; j <= 100; j += i){
                                a[j] = 0;
                        }
                }
        }
        cout << res << '\n';
}