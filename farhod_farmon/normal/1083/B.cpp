#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 500500;

using namespace std;

int n;
long long k;
int G;
int d[N * 4][2];
long long lev[N];
bool ban[N * 4];
string s, t;

void dfs(int x, int l = 0)
{
        for(int tp: {0, 1}){
                int y = d[x][tp];
                if(ban[y]){
                        continue;
                }
                if(!y){
                        lev[l + 1]++;
                }
                else{
                        dfs(y, l + 1);
                }
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k >> s >> t;
        int x = 0;
        for(int i = 0; i < n; i++){
                int g = s[i] - 'a';
                if(!d[x][g]){
                        d[x][g] = ++G;
                }
                if(g == 1){
                        if(!d[x][0]){
                                d[x][0] = ++G;
                        }
                        ban[d[x][0]] = 1;
                }
                x = d[x][g];
        }
        x = 0;
        for(int i = 0; i < n; i++){
                int g = t[i] - 'a';
                if(!d[x][g]){
                        d[x][g] = ++G;
                }
                if(g == 0){
                        if(!d[x][1]){
                                d[x][1] = ++G;
                        }
                        ban[d[x][1]] = 1;
                }
                x = d[x][g];
        }
        dfs(0);
        long long ans = n;
        k--;
        if(k){
                int same = 0;
                while(same < n && s[same] == t[same]){
                        same++;
                }
                ans += n - same;
                k--;
        }
        long long all = 0;
        for(int i = 1; i <= n && k; i++){
                lev[i] += all;
                long long g = min(k, lev[i]);
                ans += g * (n - i + 1);
                k -= g;
                all += lev[i];
        }
        cout << ans << "\n";
}