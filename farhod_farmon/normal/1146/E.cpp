#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

struct seg
{
        int t[4 * N + 10][2];

        seg()
        {
                for(int i = 0; i < 4 * N + 10; i++){
                        t[i][0] = 0;
                        t[i][1] = 1;
                }
        }
        void push(int x)
        {
                if(t[x * 2][0] == 0){
                        t[x * 2][0] = t[x][0];
                } else{
                        t[x * 2][0] = t[x][1];
                }
                if(t[x * 2][1] == 0){
                        t[x * 2][1] = t[x][0];
                } else{
                        t[x * 2][1] = t[x][1];
                }
                if(t[x * 2 + 1][0] == 0){
                        t[x * 2 + 1][0] = t[x][0];
                } else{
                        t[x * 2 + 1][0] = t[x][1];
                }
                if(t[x * 2 + 1][1] == 0){
                        t[x * 2 + 1][1] = t[x][0];
                } else{
                        t[x * 2 + 1][1] = t[x][1];
                }
                t[x][0] = 0;
                t[x][1] = 1;
        }
        void upd(int x, int l, int r, int tl, int tr, vector < int > y)
        {
                if(tl > tr){
                        return;
                }
                if(l == tl && r == tr){
                        if(t[x][0] == 0){
                                t[x][0] = y[0];
                        } else{
                                t[x][0] = y[1];
                        }
                        if(t[x][1] == 0){
                                t[x][1] = y[0];
                        } else{
                                t[x][1] = y[1];
                        }
                        return;
                }
                push(x);
                int m = (l + r) / 2;
                upd(x * 2, l, m, tl, min(m, tr), y);
                upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, y);
        }
        int get(int x, int l, int r, int g)
        {
                if(l == r){
                        return t[x][0];
                }
                push(x);
                int m = (l + r) / 2;
                if(g <= m){
                        return get(x * 2, l, m, g);
                } else{
                        return get(x * 2 + 1, m + 1, r, g);
                }
        }
};

int n;
int q;
int a[N];
seg t1, t2;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> q;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }

        for(int i = 1; i <= q; i++){
                char c;
                int x;
                cin >> c >> x;
                if(c == '<'){
                        if(x > 0){
                                t1.upd(1, 1, N, x, N, {1, 1});
                                t1.upd(1, 1, N, 1, x - 1, {1, 0});
                                t2.upd(1, 1, N, 1, x - 1, {1, 0});
                                t2.upd(1, 1, N, x, N, {0, 0});
                        } else{
                                t1.upd(1, 1, N, -x + 1, N, {1, 1});
                                t2.upd(1, 1, N, -x + 1, N, {0, 0});
                        }
                } else{
                        if(x < 0){
                                t2.upd(1, 1, N, -x, N, {1, 1});
                                t2.upd(1, 1, N, 1, -x - 1, {1, 0});
                                t1.upd(1, 1, N, 1, -x - 1, {1, 0});
                                t1.upd(1, 1, N, -x, N, {0, 0});
                        } else{
                                t2.upd(1, 1, N, x + 1, N, {1, 1});
                                t1.upd(1, 1, N, x + 1, N, {0, 0});
                        }
                }
        }

        for(int i = 1; i <= n; i++){
                if(a[i] == 0){
                        cout << a[i] << " ";
                } else if(a[i] > 0){
                        if(t2.get(1, 1, N, a[i])){
                                cout << -a[i] << " ";
                        } else{
                                cout << a[i] << " ";
                        }
                } else{
                        if(t1.get(1, 1, N, - a[i])){
                                cout << - a[i] << " ";
                        } else{
                                cout << a[i] << " ";
                        }
                }
        }
}