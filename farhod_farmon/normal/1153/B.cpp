#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int n;
int m;
int h;
int a[N];
int b[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> h;
        for(int i = 1; i <= m; i++){
                cin >> b[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        int x;
                        cin >> x;
                        cout << x * min(a[i], b[j]) << " \n"[j == m];
                }
        }
}