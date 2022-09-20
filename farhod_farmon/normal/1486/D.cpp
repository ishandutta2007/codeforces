#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int n, k;
int a[N], s[N];

bool can(int m)
{
        int mn = 1e9;
        for(int i = 1; i <= n; i++){
                s[i] = (s[i - 1] + (a[i] >= m ? 1 : -1));
                if(i - k >= 0){
                        mn = min(mn, s[i - k]);
                }
                if(s[i] > mn){
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

        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        int l = 1, r = n;
        while(l < r){
                int m = (l + r) / 2;
                if(can(m + 1)){
                        l = m + 1;
                } else{
                        r = m;
                }
        }
        cout << l << '\n';
}