#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define fi first
#define se second
#define ll long long

const int N = 1000100;
const long long m1 = 1e9 + 3;
const long long m2 = 1e9 + 7;

using namespace std;

int n;
int m;
int f1;
int f2;
string s;
string t;
pair < ll, ll > p[N];
pair < ll, ll > h[N];

pair < ll, ll > get(int l, int r)
{
        pair < ll, ll > f = {h[r].fi - h[l - 1].fi, h[r].se - h[l - 1].se};
        if(f.fi < 0)f.fi += m1;
        if(f.se < 0)f.se += m2;
        f.fi = (f.fi * p[N - l - 1].fi) % m1;
        f.se = (f.se * p[N - l - 1].se) % m2;
        return f;
}

bool solve(int l1, int l2)
{
        int fi = -1;
        for(int i = 0, j = 1; i < s.size(); i++){
                if(s[i] == s[0]){
                        if(get(1, l1) != get(j, j + l1 - 1)){
                                return false;
                        }
                        j += l1;
                }
                else{
                        if(fi == -1){
                                fi = j;
                                if(l1 == l2 && get(1, l1) == get(j, j + l1 - 1)){
                                        return false;
                                }
                        }
                        else{
                                if(get(fi, fi + l2 - 1) != get(j, j + l2 - 1)){
                                        return false;
                                }
                        }
                        j += l2;
                }
        }
        return true;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> s >> t;
        p[0] = {1, 1};
        for(int i = 1; i < N; i++){
                p[i].fi = (29 * p[i - 1].fi) % m1;
                p[i].se = (31 * p[i - 1].se) % m2;
        }
        for(int i = 0; i < t.size(); i++){
                t[i] = t[i] - 'a' + 1;
                h[i + 1].fi = (h[i].fi + p[i + 1].fi * t[i]) % m1;
                h[i + 1].se = (h[i].se + p[i + 1].se * t[i]) % m2;
        }
        m = t.size();
	for(int i = 0; i < s.size(); i++){
                f1 += s[i] == s[0];
                f2 += s[i] != s[0];
	}
	int ans = 0;
	for(int i = 0; i < m; i++){
                long long l1 = (i + 1);
                if(l1 * f1 >= m || (m - l1 * f1) % f2 != 0){
                        continue;
                }
                ans += solve(l1, (m - l1 * f1) / f2);
	}
	cout << ans << "\n";
}