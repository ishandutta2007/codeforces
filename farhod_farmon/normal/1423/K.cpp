#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000100;

using namespace std;

int n;
int res[N];
int f[N];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        res[1] = 1;
        for(int i = 2; i < N; i++){
                res[i] += res[i - 1];
                if(!f[i]){
                        res[i] += 1;
                        if(1ll * i * i < N){
                                res[i * i] -= 1;
                                for(int j = i * i; j < N; j += i){
                                        f[j] = 1;
                                }
                        }
                }
        }
        int q;
        scanf("%d", &q);
        for(int i = 1; i <= q; i++){
                scanf("%d", &n);
                printf("%d\n", res[n]);
        }
}