#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int l[5005], r[5005], a[5005];
int cnt1[5005], cnt2[5005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int n, q;
    cin>>n>>q;
    memset(a, 0, sizeof(a));
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
    for(int i = 1; i <= q; i++){
        cin>>l[i]>>r[i];
        a[l[i]]++;
        a[r[i] + 1]--;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        a[i] += a[i-1];
        cnt += (a[i] != 0);
    }
    for(int i = 1; i <= n; i++){
        cnt1[i] = cnt1[i-1];
        cnt1[i] += (a[i] == 1);
        cnt2[i] = cnt2[i-1];
        cnt2[i] += (a[i] == 2);
    }
    int ans = 0;
    for(int i = 1; i <= q; i++){
        for(int j = i+1; j <= q; j++){
            if(r[i] < l[j] || r[j] < l[i]){
                int tcnt = cnt - (cnt1[r[i]] - cnt1[l[i]-1]);
                tcnt -= (cnt1[r[j]] - cnt1[l[j]-1]);
                ans = max(ans, tcnt);
            }else{
                int l1 = min(l[i], l[j]);
                int r1 = max(l[i], l[j]) - 1;
                int l2 = max(l[i], l[j]);
                int r2 = min(r[i], r[j]);
                int l3 = min(r[i], r[j]) + 1;
                int r3 = max(r[i], r[j]);
                int tcnt = cnt;
                tcnt -= (cnt1[r1] - cnt1[l1-1]);
                tcnt -= (cnt1[r3] - cnt1[l3-1]);
                tcnt -= (cnt2[r2] - cnt2[l2-1]);
                ans = max(ans, tcnt);
            }
        }
    }
    cout<<ans<<endl;
}