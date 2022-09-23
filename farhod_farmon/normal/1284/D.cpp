#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int a[N];
int b[N];
int t[4 * N];
int lz[4 * N];

void upd(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return;
        } else if(l == tl && r == tr){
                t[x] = lz[x] = 1;
                return;
        }
        int m = (l + r) / 2;
        t[x * 2] |= lz[x];
        lz[x * 2] |= lz[x];
        t[x * 2 + 1] |= lz[x];
        lz[x * 2 + 1] |= lz[x];

        upd(x * 2, l, m, tl, min(m, tr));
        upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
        t[x] = t[x * 2] | t[x * 2 + 1];
}

int get(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return 0;
        } else if(l == tl && r == tr){
                return t[x];
        }
        int m = (l + r) / 2;
        t[x * 2] |= lz[x];
        lz[x * 2] |= lz[x];
        t[x * 2 + 1] |= lz[x];
        lz[x * 2 + 1] |= lz[x];

        return get(x * 2, l, m, tl, min(m, tr)) | get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
}

int solve(vector < pair < int, int > > A, vector < pair < int, int > > B)
{
        for(int i = 0; i < A.size(); i++){
                if(A[i].se < 0){
                        A[i].fi += 1;
                }
        }
        for(int i = 1; i < 4 * N; i++){
                t[i] = lz[i] = 0;
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        for(int i = 0, j = 1; i < B.size(); i++){
                if(i > 0 && B[i].fi > B[i - 1].fi){
                        j += 1;
                }
                if(B[i].se > 0){
                        a[B[i].se] = j;
                } else{
                        b[-B[i].se] = j;
                }
        }
        for(auto p: A){
                int i = p.se;
                if(i > 0){
                        if(get(1, 1, 2 * n, a[i], b[i]) > 0){
                                return 1;
                        }
                } else{
                        i = -i;
                        upd(1, 1, 2 * n, a[i], b[i]);
                }
        }
        return 0;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n;
        vector < pair < int, int > > A;
        vector < pair < int, int > > B;
        for(int i = 1; i <= n; i++){
                int l1, r1, l2, r2;
                cin >> l1 >> r1 >> l2 >> r2;

                A.push_back({l1, i});
                A.push_back({r1, - i});

                B.push_back({l2, i});
                B.push_back({r2, - i});
        }

        if(solve(A, B) | solve(B, A)){
                cout << "NO" << "\n";
        } else{
                cout << "YES" << "\n";
        }
}