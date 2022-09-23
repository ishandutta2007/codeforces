#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 200200;
const long long m1 = 1e9 + 7;
const long long m2 = 1e9 + 9;

using namespace std;

int n;
char a[N];
bool dead[N];
int s[N];
pair < long long, long long > hs[N];

long long p1[N];
long long p2[N];
int nxt[N];
int pre[N];

pair < long long, long long > get(int l, int r)
{
        pair < long long, long long > res = hs[r];
        res.fi -= hs[l - 1].fi;
        res.se -= hs[l - 1].se;
        if(res.fi < 0)res.fi += m1;
        if(res.se < 0)res.se += m2;

        int cl = s[nxt[l]], cr = s[r];
        if(dead[l - 1]){
                int i = nxt[l];
                if(i <= r && a[i] == 2){
                        res.fi -= p1[cl] * a[i] % m1;
                        res.se -= p2[cl] * a[i] % m2;
                        if(res.fi < 0)res.fi += m1;
                        if(res.se < 0)res.se += m2;
                        cl += 1;
                } else{
                        res.fi = res.fi * p1[0] % m1;
                        res.se = res.se * p2[0] % m2;
                        res.fi += p1[cl] * 2 % m1;
                        res.se += p2[cl] * 2 % m2;
                        if(res.fi >= m1)res.fi -= m1;
                        if(res.se >= m2)res.se -= m2;
                        cr += 1;
                }
        }
        if(dead[r]){
                int i = pre[r];
                if(i >= l && a[i] == 2){
                        res.fi -= p1[cr] * a[i] % m1;
                        res.se -= p2[cr] * a[i] % m2;
                        if(res.fi < 0)res.fi += m1;
                        if(res.se < 0)res.se += m2;
                        cr -= 1;
                } else{
                        cr += 1;
                        res.fi += p1[cr] * 2 % m1;
                        res.se += p2[cr] * 2 % m2;
                        if(res.fi >= m1)res.fi -= m1;
                        if(res.se >= m2)res.se -= m2;
                }
        }
        res.fi = res.fi * p1[N - cl] % m1;
        res.se = res.se * p2[N - cl] % m2;

        return res;
}

int gg[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        p1[0] = 3;
        p2[0] = 1337;
        for(int i = 1; i < N; i++){
                p1[i] = p1[i - 1] * p1[0] % m1;
                p2[i] = p2[i - 1] * p2[0] % m2;
        }

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                a[i] -= '0';
                a[i] += 1;

                gg[i] = gg[i - 1] + (a[i] == 1);
        }
        for(int i = 1; i <= n; i++){
                if(a[i] == 2 && a[i + 1] == 2){
                        dead[i] = true;
                        i += 1;
                }
        }
        for(int i = 1; i <= n; i++){
                hs[i] = hs[i - 1];
                s[i] = s[i - 1];
                pre[i] = pre[i - 1];
                if(dead[i] || dead[i - 1]){
                        continue;
                }
                pre[i] = i;
                s[i] += 1;
                hs[i].fi = (hs[i].fi + p1[s[i]] * a[i]) % m1;
                hs[i].se = (hs[i].se + p2[s[i]] * a[i]) % m2;
        }
        for(int i = n; i >= 1; i--){
                nxt[i] = nxt[i + 1];
                if(!dead[i - 1] && !dead[i]){
                        nxt[i] = i;
                }
        }

        int q;
        cin >> q;
        for(int i = 1; i <= q; i++){
                int x, y, l;
                cin >> x >> y >> l;
                int a0 = gg[x + l - 1] - gg[x - 1];
                int a1 = gg[y + l - 1] - gg[y - 1];
                if(a0 != a1){
                        cout << "No" << "\n";
                } else if(a0 == 0){
                        cout << "Yes" << "\n";
                } else if(get(x, x + l - 1) == get(y, y + l - 1)){
                        cout << "Yes" << "\n";
                } else{
                        cout << "No" << "\n";
                }
        }
}