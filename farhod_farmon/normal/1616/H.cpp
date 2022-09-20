#include "bits/stdc++.h"

#define fi first
#define se second

const int N = 200200;
const int mod = 998244353;

using namespace std;

void add(int &x, int y)
{
    x += y;
    if (x >= mod){
        x -= mod;
    } else if(x < 0){
        x += mod;
    }
}

int x;
int p[N];

int solve(vector<int> a, vector<int> b, int lev)
{
    if(lev == -1){
        return 1ll * (p[a.size()] - 1) * (p[b.size()] - 1) % mod;
    } else if(a.empty() || b.empty()){
        return 0;
    }
    int res = 0;
    vector<int> A[2], B[2];
    for(int x : a) A[(x >> lev) & 1].push_back(x);
    for(int x : b) B[(x >> lev) & 1].push_back(x);

    if(x & (1 << lev)){
        int f1 = solve(A[0], B[1], lev - 1);
        int f2 = solve(A[1], B[0], lev - 1);
        add(res, 1ll * f1 * f2 % mod);
        add(res, 1ll * (p[A[0].size()] - 1) * (p[B[0].size()] - 1) % mod);
        add(res, 1ll * (p[A[1].size()] - 1) * (p[B[1].size()] - 1) % mod);
        add(res, f1);
        add(res, f2);
        add(res, 1ll * f1 * (p[B[0].size()] - 1) % mod);
        add(res, 1ll * f2 * (p[B[1].size()] - 1) % mod);
        add(res, 1ll * f1 * (p[A[1].size()] - 1) % mod);
        add(res, 1ll * f2 * (p[A[0].size()] - 1) % mod);
    } else{
        add(res, solve(A[0], B[0], lev - 1));
        add(res, solve(A[1], B[1], lev - 1));
    }
    return res;
}

int solve(vector<int> a, int lev = 29)
{
    if(lev == -1){
        return p[a.size()] - 1;
    } else if(a.empty()){
        return 0;
    }
    vector<int> A, B;
    for(int x : a){
        if(x & (1 << lev)) A.push_back(x);
        else B.push_back(x);
    }
    int res = 0;
    if(x & (1 << lev)){
        add(res, solve(A, B, lev - 1));
        add(res, p[A.size()] - 1);
        add(res, p[B.size()] - 1);
    } else {
        add(res, solve(A, lev - 1));
        add(res, solve(B, lev - 1));
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n >> x;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    p[0] = 1;
    for(int i = 1; i < N; i++){
        p[i] = p[i - 1];
        add(p[i], p[i]);
    }
    cout << solve(A) << "\n";
}