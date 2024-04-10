#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100010;

using namespace std;

int n;
int m;
char a[N];
set<int> s;

void upd(int x, int g)
{
        if(x < 1 || x > n){
                return;
        } else if(a[x] != 'a' || a[x + 1] != 'b' || a[x + 2] != 'c'){
                return;
        }
        if(g == 0){
                s.erase(x);
        } else{
                s.insert(x);
        }
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                upd(i, 1);
        }
        for(int i = 1; i <= m; i++){
                int x;
                char c;
                cin >> x >> c;
                upd(x - 2, 0);
                upd(x - 1, 0);
                upd(x - 0, 0);
                a[x] = c;
                upd(x - 2, 1);
                upd(x - 1, 1);
                upd(x - 0, 1);

                cout << s.size() << "\n";
        }
}