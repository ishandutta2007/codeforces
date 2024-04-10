#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int k;
int a[N];
bool used[N];

bool can(int m)
{
        for(int i = 1, j = m + 1; i <= m; i++){
                while(j <= n && a[j] - a[i] < k){
                        j += 1;
                }
                if(j > n){
                        return false;
                }
                j += 1;
        }
        return true;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        sort(a + 1, a + n + 1);

        int l = 0, r = n / 2;
        while(l < r){
                int m = (l + r) / 2;
                if(can(m + 1)){
                        l = m + 1;
                } else{
                        r = m;
                }
        }

        cout << l << "\n";
}