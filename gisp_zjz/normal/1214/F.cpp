#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
const int maxn=1e6+7;
typedef pair<ll,ll>pi;
pi A[maxn],B[maxn];
ll Ans,a[maxn],b[maxn],n,m,ans[maxn];

int main(){
    scanf("%lld%lld",&m,&n);
    for (int i=0;i<n;i++) {scanf("%lld",&A[i].F);A[i].S=i;}
    for (int i=0;i<n;i++) {scanf("%lld",&B[i].F);B[i].S=i;}
    sort(A,A+n);sort(B,B+n);
    for (int i=0;i<n;i++) a[i]=A[i].F,b[i]=B[i].F;
    for (int i=0;i<n;i++) a[i]+=m,b[i+n]=b[i]+m,b[i+n+n]=b[i]+m*2;
    for (int i=0;i<n;i++) ans[0]-=b[i],ans[i+1]+=b[i];
    for (int i=0;i<n;i++) ans[n*2-i]+=b[n*3-i-1];
    int pos=n;
    for (int i=0;i<n;i++){
        while (b[pos]<a[i]) ++pos;
        ans[0]+=a[i]; ans[pos-i]-=a[i]*2;
    }
    pos=0;
    for (int i=n;i<n+n;i++){
        while (pos<n&&a[pos]<=b[i]) ++pos;
        ans[i-n+1]-=b[i]; ans[i-pos+1]+=b[i]*2; ans[i+1]-=b[i];
    }
    for (int i=1;i<=n*2;i++) ans[i]+=ans[i-1];
    pos=0;
    for (int i=1;i<=n*2;i++) if (ans[pos]>ans[i]) pos=i;
    printf("%lld\n",ans[pos]);
    for (int i=0;i<n;i++) ans[A[i].S]=B[(i+pos)%n].S;
    for (int i=0;i<n;i++) printf("%d ",ans[i]+1);puts("");
    return 0;
}