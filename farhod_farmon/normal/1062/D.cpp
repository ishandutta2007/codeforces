#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int p[N];
long long s[N];
long long f[N];

int get(int x)
{
        return x == p[x] ? x : p[x] = get(p[x]);
}

void upd(int x, int y)
{
        x = get(x);
        y = get(y);
        if(x != y){
                p[x] = y;
        }
}

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 2; i <= n; i++){
                p[i] = i;
        }
        for(int i = 2; i <= n; i++){
                for(int j = 2; j * j <= i; j++){
                        if(i % j == 0){
                                upd(i, j);
                                upd(i, i / j);
                                s[i] += i / j;
                                if(j * j != i){
                                        s[i] += j;
                                }
                        }
                }
        }
        for(int i = 2; i <= n; i++){
                f[get(i)] += s[i];
        }
        long long ans = 0;
        for(int i = 2; i <= n; i++){
                ans = max(ans, f[i]);
        }
        cout << 4ll * ans << "\n";
}