#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;

using namespace std;

int n;
int a[N];
int b[N];
int c[N];
int t[N];

void upd(int x)
{
        while(x < N){
                t[x] += 1;
                x += x & -x;
        }
}

int get(int x)
{
        int res = 0;
        while(x > 0){
                res += t[x];
                x -= x & -x;
        }
        return res;
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
        for(int i = 1; i <= n; i++){
                cin >> b[i];
                c[b[i]] = i;
        }
        long long res = 0;
        for(int i = 1; i <= n; i++){
                a[i] = c[a[i]];
                if(get(n) - get(a[i]) > 0){
                        res += 1;
                }
                upd(a[i]);
        }

        cout << res << "\n";
}