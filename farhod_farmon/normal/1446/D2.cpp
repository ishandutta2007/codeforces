#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int Q = 2 * N;

using namespace std;

int n;
int a[N];
int c[N];
int s[N];
int le[N];
int ri[N];
int f[Q];
int mx;
set < int > S;

int t[N];

void upd(int x, int y)
{
        while(x < N){
                t[x] += y;
                x += x & -x;
        }
}

int get(int x)
{
        int res = 0;
        while(x > 0){
                res += t[x];
                x -= x & -x;
        }
        return res;
}

int solve(vector < int > A)
{
        for(int i: A){
                upd(i, 1);
        }

        vector < int > del;
        vector < int > v = A;
        for(int i: A){
                auto p = S.lower_bound(i);
                if(p != S.begin()){
                        p--;
                }
                del.push_back(*p);
                v.push_back(le[*p - 1] + 1);
                S.erase(p);
        }
        for(int x: del){
                S.insert(x);
        }
        del.clear();
        reverse(A.begin(), A.end());
        for(int i: A){
                auto p = S.lower_bound(i);
                if(p == S.end()){
                        p--;
                }
                del.push_back(*p);
                v.push_back(ri[*p + 1] - 1);
                S.erase(p);
        }
        for(int x: del){
                S.insert(x);
        }

        sort(v.begin(), v.end());
        int res = 0;
        for(int i: v){
                // s[i] - get(i);
                int x = s[i] - get(i) + N, y = s[i - 1] - get(i - 1) + N;
                res = max(res, i - f[x]);
                if(f[y] == n){
                        f[y] = i - 1;
                }
                if(f[x] == n){
                        f[x] = i;
                }
        }
        for(int i: v){
                // s[i] - get(i);
                int x = s[i] - get(i) + N, y = s[i - 1] - get(i - 1) + N;
                f[x] = f[y] = n;
        }

        for(int i: A){
                upd(i, -1);
        }

        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);


        cin >> n;
        vector < vector < int > > c(n + 1, vector < int > ());
        for(int i = 0; i < Q; i++){
                f[i] = n;
        }
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                c[a[i]].push_back(i);
        }
        for(int i = 1; i <= n; i++){
                if(c[i].size() > c[mx].size()){
                        mx = i;
                }
        }

        for(int i = 1; i <= n; i++){
                s[i] = s[i - 1] + (a[i] == mx);
                if(a[i] == mx){
                        le[i] = i;
                } else{
                        le[i] = le[i - 1];
                }
        }
        ri[n + 1] = n + 1;
        for(int i = n; i >= 1; i--){
                if(a[i] == mx){
                        ri[i] = i;
                } else{
                        ri[i] = ri[i + 1];
                }
        }

        for(int x: c[mx]){
                S.insert(x);
        }

        int res = 0;
        //cout << mx << endl;
        for(int i = 1; i <= n; i++){
                if(c[i].empty() || i == mx){
                        continue;
                }
                //cout << mx << " " << i << " " << solve(c[i]) << "\n";
                res = max(res, solve(c[i]));
        }
        cout << res << "\n";
}