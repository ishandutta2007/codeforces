#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int a[N];

pair < int, int > ask(int l, int r)
{
        cout << "? " << l << " " << r << endl;
        int i, j;
        cin >> i >> j;
        return {i, j};
}

pair < int, int > ask(int l)
{
        return ask(l, l);
}

void solve(int l, int r, int X, int Y)
{
        if(l > r){
                return;
        } else if(X == Y){
                for(int i = l; i <= r; i++){
                        a[i] = X;
                }
                return;
        } else if(l + 1 == r){
                a[l] = X;
                a[r] = Y;
                return;
        }
        auto shit = ask(l, r);
        if(shit.fi == X){
                for(int i = 0; i < shit.se; i++){
                        a[l + i] = X;
                }
                solve(l + shit.se, r, ask(l + shit.se).fi, Y);
                return;
        } else if(shit.fi == Y){
                for(int i = 0; i < shit.se; i++){
                        a[r - i] = Y;
                }
                solve(l, r - shit.se, X, ask(r - shit.se).fi);
                return;
        }
        int m = (l + r) / 2;
        auto g = ask(m);
        assert(g.fi != X && g.fi != Y);
        solve(l, m, X, g.fi);
        solve(m, r, g.fi, Y);
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        solve(1, n, ask(1).fi, ask(n).fi);

        cout << "!";
        for(int i = 1; i <= n; i++) cout << " " << a[i];
        cout << endl;
}