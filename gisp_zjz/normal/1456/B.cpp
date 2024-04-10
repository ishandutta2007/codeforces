#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=1e6+200;
const int M=1000000007;
int n;
int solve(vi &a,bool ok){
    int n=a.size();
    for (int i=0;i<n-1;i++) if (a[i]>a[i+1]) return 0;
    if (n<=2) return M;
    int high=-1;
    for (int i=0;i<30;i++) if (a[n-1]&(1<<i)) high=i;
    if (high==-1) return 0;
    vi b=a; b.resize(n-2);
    if (a[n-3]&(1<<high)){
        return 1;
    } else if (a[n-2]&(1<<high)){
        int ret=M;
        int tot=0,xsum=a[n-2];
        for (int i=n-3;i>=0;i--){
            xsum^=a[i]; tot++;
            if (xsum>a[n-1]) break;
        }
        if (xsum>a[n-1]) ret=min(ret,tot);
        if (ok) ret=min(ret,solve(b,ok));
        b.pb(a[n-2]^a[n-1]);
        ret=min(ret,solve(b,0)+1);
        return ret;
    } else {
        b.pb(a[n-2]);
        if (ok) return solve(b,ok); else return M;
    }
}
int main(){
    scanf("%d",&n);
    vi a(n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    int ans=solve(a,1);
    if (ans==M) puts("-1"); else printf("%d\n",ans);
    return 0;
}