#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 4000000
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,a[N],s[N],p0[N],p1[N];ll ans,x;
int main(){
	scanf("%d",&n);p0[0]=1;
	rep(i,1,n)for(scanf("%I64d",&x);x;x>>=1)if(x&1)a[i]++;
	rep(i,1,n){
		s[i]=a[i]+s[i-1];p0[i]=p0[i-1];p1[i]=p1[i-1];
		if(s[i]&1)p1[i]++;else p0[i]++;
	}
	rep(i,1,min(121,n)){x=a[i];
		dep(j,i-1,1){
			if(a[j]>x)x=a[j];
			if((!((s[i]-s[j-1])&1))&&(s[i]-s[j-1]>=x*2))ans++;
		}
	}
	rep(i,122,n){x=a[i];
		dep(j,i-1,i-120){
			if(a[j]>x)x=a[j];
			if((!((s[i]-s[j-1])&1))&&(s[i]-s[j-1]>=x*2))ans++;
		}
		if(s[i]&1)ans+=p1[i-122];else ans+=p0[i-122];
	}
	printf("%I64d",ans);
}