#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 998244353;

using namespace std;

int n;
int m;
pair < int, int > a[N];
pair < int, int > b[N];

bool good(int k)
{
        for(int i = 1; i <= m; i++){
                b[i].fi = (a[i].fi + k) % n;
                b[i].se = (a[i].se + k) % n;
                if(b[i].fi > b[i].se){
                        swap(b[i].fi, b[i].se);
                }
        }
        sort(b + 1, b + m + 1);
        for(int i = 1; i <= m; i++){
                if(a[i] != b[i]){
                        return false;
                }
        }
        return true;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                cin >> a[i].fi >> a[i].se;
                a[i].fi -= 1;
                a[i].se -= 1;
                if(a[i].fi > a[i].se){
                        swap(a[i].fi, a[i].se);
                }
        }
        sort(a + 1, a + m + 1);
        for(int i = 1; i < n; i++){
                if(n % i == 0 && good(i)){
                        cout << "Yes" << "\n";
                        return 0;
                }
        }
        cout << "No" << "\n";
}