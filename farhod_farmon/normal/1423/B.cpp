#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
int m;
int p[N];
bool used[N];
vector < int > v[N], cl;
int A[N], B[N], C[N];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool dfs(int x)
{
        if(used[x]){
                return false;
        }
        cl.push_back(x);
        used[x] = true;
        for(int y: v[x]){
                if(p[y] == -1 || dfs(p[y])){
                        p[y] = x;
                        return true;
                }
        }
        return false;
}

int solve(int d)
{
        vector < int > us(n + 1, 0);
        vector < int > ord;
        for(int i = 1; i <= n; i++){
                v[i].clear();
                p[i] = -1;
                used[i] = 0;
        }
        for(int i = 1; i <= m; i++){
                if(C[i] <= d){
                        v[A[i]].push_back(B[i]);
                        us[B[i]] = 1;
                }
        }
        for(int i = 1; i <= n; i++){
                if(v[i].empty() || !us[i]) return 0;


                shuffle(v[i].begin(), v[i].end(), rng);
                bool good = false;
                for(int j: v[i]){
                        if(p[j] == -1){
                                good = true;
                                p[j] = i;
                                break;
                        }
                }

                if(good) continue;

                ord.push_back(i);
        }
        shuffle(ord.begin(), ord.end(), rng);

        for(int x: ord){
                if(!dfs(x)){
                        return 0;
                }
                for(int x: cl){
                        used[x] = 0;
                }
                cl.clear();
        }
        return n;
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        scanf("%d%d", &n, &m);
        vector < int > v;
        for(int i = 1; i <= m; i++){
                scanf("%d%d%d", &A[i], &B[i], &C[i]);
                v.push_back(C[i]);
        }
        sort(v.begin(), v.end());

        if(solve(v[m - 1]) != n){
                printf("%d\n", -1);
                return 0;
        }
        int l = 0, r = m - 1;
        while(l < r){
                int m = (l + r) / 2;
                if(solve(v[m]) == n){
                        r = m;
                } else{
                        l = m + 1;
                }
        }
        printf("%d\n", v[l]);
}