#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int M=998244353;
const int maxn=1e6+10;
int _,n,a[maxn],b[maxn],l,r,mid;
bool check(int k){
    int m=n+k,rm=m-m/4;
    int A=0,B=0;
    for (int i=1;i<=k;i++) a[n+i]=100;
    for (int i=m;i>m-rm;i--) A+=a[i];
    for (int i=n;i>max(0,n-rm);i--) B+=b[i];
    return A>=B;
}
void solve(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) scanf("%d",&b[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    if (check(0)) puts("0");
    else {
        l=0; r=n;
        while (r-l>1){
            mid=(l+r)>>1;
            if (check(mid)) r=mid; else l=mid;
        }
        printf("%d\n",r);
    }
}
int main(){
    scanf("%d",&_);
    while (_--) solve();
}