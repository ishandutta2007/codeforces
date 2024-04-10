#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1024 * 2;
const int mod = 998244353;

using namespace std;

int k;
int C;
int dead[N];

void ask(int x)
{
        C -= 1;
        assert(C >= 0);
        cout << "? " << x << endl;
        char res;
        cin >> res;
        if(res == 'Y'){
                dead[x] = true;
        }
}

vector < int > v;
void run(int l, int r)
{
        for(int i = l; i <= r; i++){
                if(!dead[i]){
                        v.push_back(i);
                }
        }
}

void rest()
{
        cout << "R" << endl;
        v.clear();
}

void solve(int l, int r)
{
        int n = r - l + 1;
        if(n == k){
                rest();
                run(l, r);
                for(int x: v){
                        ask(x);
                }
                return;
        }


        int m = (l + r) / 2;
        solve(l, m);
        solve(m + 1, r);

        vector < pair < int, int > > A, B;
        for(int i = l; i <= m; i += k){
                A.push_back({i, i + k - 1});
        }
        for(int i = m + 1; i <= r; i += k){
                B.push_back({i, i + k - 1});
        }

        int g = B.size();
        vector < pair < int, int > > saved;
        for(int shift = 0; shift < g; shift += 1){
                rest();
                for(int i = 0; i < A.size(); i++){
                        run(A[i].fi, A[i].se);
                        run(B[(i + shift) % g].fi, B[(i + shift) % g].se);
                }
                for(int x: v){
                        ask(x);
                }
                saved.push_back(B[(g - 1 + shift) % g]);
                saved.push_back(A[0]);
        }
        for(int i = 0; i < saved.size(); i += 2){
                rest();
                run(saved[i].fi, saved[i].se);
                run(saved[i + 1].fi, saved[i + 1].se);
                for(int x: v){
                        ask(x);
                }
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int n;
        cin >> n >> k;
        C = 3 * n * n / (2 * k);
        solve(1, n);

        int res = 0;
        for(int i = 1; i <= n; i++){
                if(!dead[i]){
                        res += 1;
                }
        }
        cout << "! " << res << endl;
}