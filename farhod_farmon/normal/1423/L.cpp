#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 1001;
const int mod = 1e9 + 7;

using namespace std;

int n, s, d;
int id[N];
int mask[N];
bitset < N > a[N];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        scanf("%d%d%d", &n, &s, &d);
        for(int i = 0; i < n; i++){
                id[i] = -1;
        }
        vector < int > cyc;
        for(int i = 0; i < s; i++){
                bitset < N > cur;
                int l;
                scanf("%d", &l);
                for(int j = 1; j <= l; j++){
                        int x;
                        scanf("%d", &x);
                        x -= 1;
                        cur[x] = 1;
                }
                int cur_mask = (1 << i), good = false;
                for(int j = 0; j < n; j++){
                        if(cur[j] == 0) continue;
                        if(id[j] != -1){
                                cur ^= a[id[j]];
                                cur_mask ^= mask[id[j]];
                        } else{
                                good = true;
                                id[j] = i;
                                break;
                        }
                }
                if(good){
                        a[i] = cur;
                        mask[i] = cur_mask;
                        continue;
                }
                cyc.push_back(cur_mask);
        }
        set < int > S;
        queue < int > Q;
        S.insert(0);
        Q.push(0);
        while(!Q.empty()){
                int x = Q.front();
                Q.pop();
                for(int y: cyc){
                        if(S.find(x ^ y) == S.end()){
                                Q.push(x ^ y);
                                S.insert(x ^ y);
                        }
                }
        }
        cyc.clear();
        for(auto x: S){
                cyc.push_back(x);
        }

        for(int i = 0; i < d; i++){
                bitset < N > cur;
                int l;
                scanf("%d", &l);
                for(int j = 0; j < l; j++){
                        int x;
                        scanf("%d", &x);
                        cur[x - 1] = 1;
                }
                int res = n + 1;
                int cur_mask = 0;
                for(int j = 0; j < n; j++){
                        if(!cur[j]) continue;
                        if(id[j] == -1){
                                res = -1;
                                break;
                        }
                        cur_mask ^= mask[id[j]];
                        cur ^= a[id[j]];
                }
                if(res == -1){
                        printf("-1\n");
                        continue;
                }
                for(int x: cyc){
                        res = min(res, (int)__builtin_popcount(cur_mask ^ x));
                }
                printf("%d\n", res);
        }
}