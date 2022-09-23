#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
int b[N];

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
        for(int i = 1, l = 1, r = n; i <= n; i++){
                if(i & 1){
                        b[l++] = a[i];
                }
                else{
                        b[r--] = a[i];
                }
        }
        for(int i = 1; i <= n; i++){
                cout << b[i] << " ";
        }
}