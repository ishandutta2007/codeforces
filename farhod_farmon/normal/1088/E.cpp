#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 300300;

using namespace std;

int n;
int a[N];
long long d[N];
vector < int > v[N];
long long best;

long long get_max(int x, int p = -1)
{
        long long best = -1e18;
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                best = max(best, get_max(y, x));
                d[x] += max(0ll, d[y]);
        }
        return max(best, d[x]);
}

int get_cnt(int x, int p = -1)
{
        int cnt = 0;
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                cnt += get_cnt(y, x);
                d[x] += max(0ll, d[y]);
        }
        if(d[x] >= best){
                cnt++;
                d[x] = 0;
        }
        return cnt;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        for(int i = 1; i <= n; i++){
                d[i] = a[i];
        }
        long long ans = get_max(1);
        best = ans;
        for(int i = 1; i <= n; i++){
                d[i] = a[i];
        }
        long long cnt = get_cnt(1);
        cout << ans * cnt << " " << cnt << "\n";
}