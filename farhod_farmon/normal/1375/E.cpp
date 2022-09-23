#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
const int mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
int p[N];
int bad[N];
int gg[N][N];
set < int > S;
vector < pair < int, int > > res;

void upd(int i, int j)
{
        swap(a[i], a[j]);
        swap(p[a[i]], p[a[j]]);
        assert(gg[i][j]);
        gg[i][j] = 0;
        res.push_back({i, j});
        bad[i] -= 1;
        S.erase(a[j]);
        if(bad[i] > 0){
                S.insert(a[i]);
        }
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        scanf("%d", &n);

        map < int, vector < int > > id;
        for(int i = 1; i <= n; i++){
                scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; i++){
                id[a[i]].push_back(i);
        }
        int cnt = 0;
        for(auto v: id){
                for(int x: v.se){
                        a[x] = (++cnt);
                }
        }

        for(int i = 1; i <= n; i++){
                for(int j = i + 1; j <= n; j++){
                        if(a[i] > a[j]){
                                gg[i][j] = 1;
                                bad[i] += 1;
                                S.insert(a[i]);
                        }
                }
                p[a[i]] = i;
        }

        while(!S.empty()){
                int x = *S.begin();
                upd(p[x], p[x - 1]);
        }
        printf("%d\n", (int)res.size());
        for(auto p: res){
                printf("%d %d\n", p.fi, p.se);
        }
}