#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 998244353;

using namespace std;

int n;
int a[N];
int b[N];

void solve(int x1, int y1, int x2, int y2)
{
        int cnt = -1;
        for(int i = 1; i <= n; i++){
                if(x1 <= a[i] && a[i] <= x2 && y1 <= b[i] && b[i] <= y2){
                        if(a[i] != x1 && a[i] != x2 && b[i] != y1 && b[i] != y2){
                                if(cnt != -1) return;
                                cnt = i;
                        }
                } else{
                        if(cnt != -1) return;
                        cnt = i;
                }
        }
        if(cnt != -1){
                cout << a[cnt] << " " << b[cnt] << "\n";
                exit(0);
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        n = n * 4 + 1;
        for(int i = 1; i <= n; i ++){
                cin >> a[i] >> b[i];
        }
        for(int i = 0; i < 50; i++){
                for(int j = 0; j < 50; j++){
                        for(int i1 = i + 1; i1 <= 50; i1++){
                                for(int j1 = j + 1; j1 <= 50; j1++){
                                        solve(i, j, i1, j1);
                                }
                        }
                }
        }
}