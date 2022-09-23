#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int q;
int a[N];
int t[3][N];
set < int > s[3];

int id(char c)
{
        if(c == 'R'){
                return 0;
        }
        if(c == 'S'){
                return 1;
        }
        return 2;
}

void upd(int x, int y, int g)
{
        while(y < N){
                t[x][y] += g;
                y += y & -y;
        }
}

int su(int x, int y)
{
        int res = 0;
        while(y > 0){
                res += t[x][y];
                y -= y & -y;
        }
        return res;
}

int get()
{
        int res = 0;
        for(int i = 0; i < 3; i++){
                int j = (i - 1 + 3) % 3;
                if(s[j].empty()){
                        res += s[i].size();
                        continue;
                }
                int l = *s[j].begin(), r = *(--s[j].end());
                int h = 3 - i - j;
                if(s[h].empty()){
                        continue;
                }
                int tl = *s[h].begin(), tr = *(--s[h].end());
                res += su(i, min(l, tr));
                res += s[i].size() - su(i, max(r, tl));
                res += max(0, su(i, min(tr, r)) - su(i, max(l, tl)));
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> q;
        for(int i = 1; i <= n; i++){
                char c;
                cin >> c;
                a[i] = id(c);
                upd(a[i], i, 1);
                s[a[i]].insert(i);
        }
        cout << get() << "\n";
        for(int i = 1; i <= q; i++){
                int x;
                char c;
                cin >> x >> c;
                s[a[x]].erase(x);
                upd(a[x], x, -1);
                a[x] = id(c);
                s[a[x]].insert(x);
                upd(a[x], x, 1);
                cout << get() << "\n";
        }
}