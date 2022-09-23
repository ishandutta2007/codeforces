#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

#define fi first
#define se second

const int N = 300300;
const int Q = 100100;
const int MAGIC = 130;

using namespace std;

int n;
int m;
int a[N];

bool can(int k)
{
        int cur = 0;
        for(int i = 1; i <= n; i++){
                int l = a[i], r = (a[i] + k) % m;
                if(l <= r){
                        if(max(l, cur) <= r){
                                cur = max(cur, l);
                        } else{
                                return false;
                        }
                } else{
                        if(cur > r){
                                cur = max(cur, l);
                        }
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
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        int l = 0, r = m;
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