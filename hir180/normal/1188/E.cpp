#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define mod 998244353
ll f[1000005],r[1000005];
int n,a[100005];
ll modpow(ll a,ll n){
    ll ret = 1;
    while(n){
        if(n&1) ret = ret*a%mod;
        a = a*a%mod;
        n /= 2;
    }
    return ret;
}
int cnt[100005];
int cc[1000005];
ll C(int a,int b){
    if(a<0||b<0||a<b) return 0;
    return f[a]*r[b]%mod*r[a-b]%mod;
}
int main(){
    scanf("%d",&n);
    rep(i,n) {scanf("%d",&a[i]);cc[a[i]]++;}
    sort(a,a+n);
    int up = a[n-1];
    for(int i=0;i<n;i++) if(a[i] < i) { up = i-1; break; }
    f[0] = 1;
    for(int i=1;i<1000005;i++) f[i] = f[i-1]*1LL*i%mod;
    r[1000004] = modpow(f[1000004],mod-2);
    for(int i=1000003;i>=0;i--) r[i] = r[i+1]*1LL*(i+1)%mod;
    int cur = 0;
    int nxt = 0;
    ll ans = 0;
    for(int i=0;i<=up;i++){
        cur += cnt[(i+n-1)%n];
        while(nxt < n && a[nxt] < i) nxt++;
        //icur
        //(i-cur)n - (i-cur-n+nxt)n
        ans += C(i-cur+n-1,n-1) - C(i-cur-n+nxt+n-1,n-1) ;
        cnt[i%n] += cc[i];
    }
    cout << (ans%mod+mod)%mod << endl;
}