#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,a[1000002],ans,cnt,head[1000002],b[1000002],mn;
struct node{
	int x,y;
	bool operator <(const node a)const{return x<a.x;}
}now;
vector<node>A,B;
signed main(){
	n=read();
	for(re int i=1;i<=n;++i){
		a[i]=read(),b[i]=read();
		if(a[i]>=a[1])A.push_back((node){a[i],b[i]});
		else B.push_back((node){a[i],b[i]});ans+=b[i];
	}
	re int ssum=ans;
	sort(A.begin(),A.end()),sort(B.begin(),B.end());
	re int mx=a[1];
	for(re int i=0;i<A.size();++i){
		if(A[i].x>mx)ans+=A[i].x-mx;
		mx=max(mx,A[i].x+A[i].y);
	}
	mn=2e18;
	if(!B.size()){
		printf("%lld",ans);
		return 0;
	}
	mx=B[0].x;
	re int sum=0;
	for(re int i=0;i<B.size();++i){
		if(B[i].x>mx)sum+=B[i].x-mx;
		mx=max(mx,B[i].x+B[i].y);
		mn=min(mn,sum+max(0ll,a[1]-B[i].x-B[i].y));
	}
	ans=0;
	mx=max(mx,a[1]);
	for(re int i=0;i<A.size();++i){
		if(A[i].x>mx)ans+=A[i].x-mx;
		mx=max(mx,A[i].x+A[i].y);
	}
	printf("%lld",ans+mn+ssum);
	
}