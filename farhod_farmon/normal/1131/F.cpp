#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int p[N];
int l[N];
int r[N];
int nxt[N];
bool used[N];

int get(int x)
{
        return x == p[x] ? x : p[x] = get(p[x]);
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                p[i] = l[i] = r[i] = i;
        }
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                x = get(x);
                y = get(y);
                nxt[r[x]] = l[y];
                used[l[y]] = 1;
                p[y] = x;
                r[x] = r[y];
        }
        int x = 1;
        for(int i = 2; i <= n; i++){
                if(used[i] == 0){
                        x = i;
                }
        }
        for(int i = 1; i <= n; i++){
                cout << x << " ";
                x = nxt[x];
        }
}