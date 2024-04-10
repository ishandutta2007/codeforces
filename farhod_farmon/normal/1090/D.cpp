#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 100100;

using namespace std;

int n;
int m;
bool used[N];
set < int > s[N];
int a[N];
int b[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                s[x].insert(y);
                s[y].insert(x);
        }
        int x = -1, y;
        for(int i = 1; i <= n; i++){
                for(int j = i + 1; j <= n; j++){
                        if(s[i].find(j) == s[i].end()){
                                x = i;
                                y = j;
                                break;
                        }
                }
                if(x != -1){
                        break;
                }
        }
        if(x == -1){
                cout << "NO" << "\n";
                return 0;
        }
        cout << "YES" << "\n";
        for(int i = 1, g = 3; i <= n; i++){
                if(i == x || i == y){
                        continue;
                }
                a[i] = b[i] = g;
                g++;
        }
        a[x] = 1;
        a[y] = 2;
        b[x] = b[y] = 1;
        for(int i = 1; i <= n; i++){
                cout << a[i] << " ";
        }
        cout << "\n";
        for(int i = 1; i <= n; i++){
                cout << b[i] << " ";
        }
        cout << "\n";
}