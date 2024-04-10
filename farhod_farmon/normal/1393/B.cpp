#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int a[N];
int A, B;

void upd(int x, int g)
{
        A -= a[x] / 2;
        B -= a[x] / 4;
        a[x] += g;
        A += a[x] / 2;
        B += a[x] / 4;
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                upd(x, 1);
        }
        int q;
        cin >> q;
        for(int i = 1; i <= q; i++){
                char c;
                int x;
                cin >> c >> x;
                if(c == '+') upd(x, 1);
                else upd(x, -1);

                if(A >= 4 && B >= 1) cout << "YES\n";
                else cout << "NO\n";
        }
}