#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200100;

using namespace std;

int n;
int m;
int x[N];
int t[N];
int l[N];
int r[N];
int res[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n + m; i++){
                cin >> x[i];
        }
        for(int i = 1; i <= n + m; i++){
                cin >> t[i];
        }
        l[0] = -1;
        for(int i = 1; i <= n + m; i++){
                if(t[i] == 1){
                        l[i] = i;
                }
                else{
                        l[i] = l[i - 1];
                }
        }
        r[n + m + 1] = -1;
        for(int i = n + m; i >= 1; i--){
                if(t[i] == 1){
                        r[i] = i;
                }
                else{
                        r[i] = r[i + 1];
                }
        }
        for(int i = 1; i <= n + m; i++){
                if(t[i] == 1){
                        continue;
                }
                int dl = 1e9, dr = 1e9;
                if(l[i] != -1){
                        dl = abs(x[i] - x[l[i]]);
                }
                if(r[i] != -1){
                        dr = abs(x[i] - x[r[i]]);
                }
                if(dl <= dr){
                        res[l[i]] += 1;
                }
                else{
                        res[r[i]] += 1;
                }
        }
        for(int i = 1; i <= n + m; i++){
                if(t[i] == 1){
                        cout << res[i] << " ";
                }
        }
}