#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int pos[200005],c[200005],a[200005],n;
ll ans=0,c2[200005];
void U(int x){
	int p=x;
	while(x<=n)c[x]++,c2[x]+=p,x+=x&-x;
}
int Q1(int x){
	int r=0;
	while(x)r+=c[x],x-=x&-x;
	return r;
}
ll Q2(int x){
	ll r=0;
	while(x)r+=c2[x],x-=x&-x;
	return r;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),pos[a[i]]=i;
	for(int i=1;i<=n;i++){
		ans+=Q1(n)-Q1(pos[i]),U(pos[i]);
		int r=0,now=0;
		for(int j=17;j>=0;j--)if(r+(1<<j)<=n&&now+c[r+(1<<j)]<(i+1)/2)r+=(1<<j),now+=c[r];
		r++;
		//cout<<endl<<i<<' '<<r<<' '<<ans<<' '<<Q2(n)-Q2(r)<<' '<<Q1(n)-Q1(r)<<' '<<Q2(r-1)<<' '<<Q1(r-1)<<endl;
		int po=Q1(n)-Q1(r),pp=Q1(r-1);
		printf("%lld ",ans+Q2(n)-Q2(r)-1ll*po*(r+1+r+po)/2+1ll*(r-1+r-pp)*pp/2-Q2(r-1));
	}
	return 0;
}