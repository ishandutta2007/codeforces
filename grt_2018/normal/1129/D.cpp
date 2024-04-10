    #include <bits/stdc++.h>
     
    using namespace std;
     
    const int nax = 100 * 1000 + 10, B = 300, mod = 998244353, INF = 1e9 + 10;
    int n,k;
    int a[nax], last[nax], llast[nax];
    int val[nax], dp[nax];
     
    struct Bucket {
        int del;
        int sum[B+5];
    };
     
    Bucket bck[nax/B + 10];
     
    void rebuilt(int x) {
        for(int i = 0;  i <= B; ++i) bck[x].sum[i] = 0;
        int sm = INF;
        for(int i = x * B; i <= n && i/B == x; ++i) {
            sm = min(sm, val[i]);
        }
        bck[x].del += sm;
        for(int i = x * B; i <= n && i/B == x; ++i) {
            val[i] -= sm;
            bck[x].sum[val[i]] = (bck[x].sum[val[i]] + (i > 0 ? dp[i - 1] : 0)) % mod;
        }
        for(int i = 1; i <= B; ++i) bck[x].sum[i] = (bck[x].sum[i] + bck[x].sum[i-1]) % mod;
    }
     
    void update(int l, int r,int x) {
        if(l > r) return;
        int low = l/B, high = r/B;
        while(l <= r && l/B == low) {
            val[l++] += x;
        }
        while(l <= r && r/B == high) {
            val[r--] += x;
        }
        for(int i = low + 1; i <= high - 1; ++i) bck[i].del += x;
        rebuilt(low);
        if(low != high) rebuilt(high);
    }
     
    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cin >> n >> k;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            last[i] = llast[i] = -1;
        }
        dp[0] = 1;
        rebuilt(0);
        for(int i = 1; i <= n; ++i) {
            update(last[a[i]] + 1, i, 1);
            update(llast[a[i]] + 1, last[a[i]], -1);
            llast[a[i]] = last[a[i]];
            last[a[i]] = i;
            int cnt = 0;
            for(int j = 0; j < i/B; ++j) {
                cnt = (cnt + (k >= bck[j].del ? bck[j].sum[min(B,k - bck[j].del)] : 0)) % mod;
            }
            for(int j = (i/B) * B; j <= i; ++j) {
                cnt = (cnt + (val[j] + bck[j/B].del <= k ? (j > 0 ? dp[j - 1] : 0) : 0)) % mod;
            }
            dp[i] = cnt;
            
        }
        cout << dp[n];
    }