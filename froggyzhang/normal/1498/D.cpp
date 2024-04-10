#include<bits/stdc++.h>
using namespace std;
#define N 100010
const int inf=0x3f3f3f3f;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,ans[N],c[N],m;
int main(){
	n=read(),m=read();
	memset(ans,-1,sizeof(ans));
	ans[0]=0;
	for(int k=1;k<=n;++k){
		int t=read();
		ll x=read();
		int y=read();
		memset(c,0x3f,sizeof(c));
		if(t==1){
			for(int i=0;i<=m;++i){
				if(~ans[i])c[i]=0;
				else if(c[i]<=y)ans[i]=k;
				if(c[i]>=y)continue;
				ll z=i+(ll)ceil(1.0*x/1e5);
				if(z<=m)c[z]=min(c[z],c[i]+1);
			}	
		}
		else{
			for(int i=0;i<=m;++i){
				if(~ans[i])c[i]=0;
				else if(c[i]<=y)ans[i]=k;
				if(c[i]>=y)continue;
				ll z=(ll)ceil(i*1.0*x/1e5);
				if(z<=m)c[z]=min(c[z],c[i]+1);
			}	
		}	
	}
	for(int i=1;i<=m;++i)printf("%d ",ans[i]);
	return 0;
}