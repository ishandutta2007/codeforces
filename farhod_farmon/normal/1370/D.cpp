#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 200200;

using namespace std;

int n, k;
int a[N];
int d[N];

bool can(int m)
{
        for(int i = 1; i <= n; i++){
                d[i] = d[i - 1];
                if(a[i] <= m){
                        d[i] = max(d[i], min(i, 2));
                        if(i - 2 >= 0){
                                d[i] = max(d[i], d[i - 2] + 2);
                        }
                }
                if(d[i] + min(n - i, 1) >= k){
                        return true;
                }
        }
        return false;
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        int l = 0, r = 1e9;
        while(l < r){
                int m = (l + r) / 2;
                if(can(m)){
                        r = m;
                } else{
                        l = m + 1;
                }
        }
        cout << l << "\n";
}