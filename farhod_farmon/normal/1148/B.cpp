#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int MAGIC = 1000;
const long long mod = 998244353;

using namespace std;

int n;
int m;
int k;
int a[N];
int b[N];
int d[N];

bool can(int g)
{
        if(g <= k){
                return true;
        }
        for(int i = 0; i <= k; i++){
                if(d[g - i] <= k - i){
                        return true;
                }
        }
        return false;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int ta, tb;
        cin >> n >> m >> ta >> tb >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                a[i] += ta;
        }
        for(int i = 1; i <= m; i++){
                cin >> b[i];
        }
        for(int i = n, j = m; i >= 1; i--){
                while(j >= 1 && a[i] <= b[j]){
                        j -= 1;
                }
                d[j + 1] += 1;
        }
        for(int i = 1; i <= m; i++){
                d[i] += d[i - 1];
        }
        int l = 1, r = m + 1;
        while(l < r){
                int m = (l + r) / 2;
                if(can(m)){
                        l = m + 1;
                } else{
                        r = m;
                }
        }
        if(l == m + 1){
                cout << -1 << "\n";
        } else{
                cout << (long long)b[l] + tb << "\n";
        }
}