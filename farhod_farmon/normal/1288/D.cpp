#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const int mod = 1e9 + 7;

using namespace std;

int n;
int m;
int a[N][8];
int d[1 << 8];

pair < int, int > can(int k)
{
        for(int i = 0; i < (1 << m); i++){
                d[i] = 0;
        }
        for(int i = 0, mask; i < n; i++){
                mask = 0;
                for(int j = 0; j < m; j++){
                        if(a[i][j] >= k){
                                mask |= (1 << j);
                        }
                }
                d[mask] = i + 1;
        }
        for(int i = (1 << m) - 1; i >= 0; i--){
                if(!d[i]){
                        continue;
                }
                for(int j = 0; j < m; j++){
                        if(i & (1 << j)){
                                d[i ^ (1 << j)] = d[i];
                        }
                }
        }
        for(int i = 0; i < (1 << m); i++){
                if(d[i] && d[((1 << m) - 1) ^ i]){
                        return {d[i], d[((1 << m) - 1) ^ i]};
                }
        }
        return {-1, -1};
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        scanf("%d", &a[i][j]);
                }
        }
        int l = 0, r = 1e9;
        while(l < r){
                int m = (l + r) / 2;
                if(can(m + 1).fi != -1){
                        l = m + 1;
                } else{
                        r = m;
                }
        }
        auto res = can(l);
        printf("%d %d\n", res.fi, res.se);
}