#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 3003;

using namespace std;

int n;
int m;
int a[N];
int f1[N];
int f2[N];
int d[N][N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        if(n == 1){
                cout << 1 << "\n";
                return 0;
        }
        for(int i = n; i >= 1; i--){
                f1[i] = f1[i + 1] | (a[i] > 0);
                f2[i] = f2[i + 1] | (a[i] == 100);
        }
        queue < pair < int, int > > q;
        q.push({1, 2});
        int res = 0;
        d[1][2] = 1;
        m += 1;
        while(!q.empty()){
                int A = q.front().fi, B = q.front().se;
                q.pop();
                if(d[A][B] > m){
                        continue;
                }
                res += 1;
                if(B > n){
                        continue;
                }
                if(!d[B + 1][B + 2] && a[A] > 0 && f1[B] > 0){
                        d[B + 1][B + 2] = d[A][B] + 1;
                        q.push({B + 1, B + 2});
                }
                if(!d[A][B + 1] && a[A] > 0 && !f2[B]){
                        d[A][B + 1] = d[A][B] + 1;
                        q.push({A, B + 1});
                }
                if(!d[B][B + 1] && a[A] != 100 && f1[B]){
                        d[B][B + 1] = d[A][B] + 1;
                        q.push({B, B + 1});
                }
        }
        cout << res << "\n";
}