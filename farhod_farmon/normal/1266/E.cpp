#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 1e9 + 7;

using namespace std;

int n;
int m;
int a[N];
int b[N];
long long all;

void upd(int x, int g)
{
        if(g == 1){
                b[x] += 1;
                if(b[x] <= a[x]){
                        all -= 1;
                }
        } else{
                if(b[x] <= a[x]){
                        all += 1;
                }
                b[x] -= 1;
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                all += a[i];
        }
        cin >> m;
        map < pair < int, int >, int > d;
        for(int i = 1; i <= m; i++){
                int x, y, z;
                cin >> x >> y >> z;

                int &h = d[{x, y}];

                if(h > 0){
                        upd(h, -1);
                }
                h = z;
                if(h > 0){
                        upd(h, 1);
                }

                cout << all << "\n";
        }
}