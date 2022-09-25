#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
typedef pair<int,int> pii;
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
int f[N][21],g[N][21],n,lg[N],mx,ans[N],a[N];
inline pii Query(int l,int r){
	--r;
	int k=lg[r-l+1];
	return make_pair(max(f[l][k],f[r-(1<<k)+1][k]),min(g[l][k],g[r-(1<<k)+1][k]));	
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<n;++i){
		f[i][0]=min(a[i],a[i+1]);
		g[i][0]=max(a[i],a[i+1]);	
	}
	for(int i=2;i<=n;++i)lg[i]=lg[i>>1]+1;
	for(int j=1;j<=20;++j){
		for(int i=1;i+(1<<j)-1<n;++i){
			f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
			g[i][j]=min(g[i][j-1],g[i+(1<<j-1)][j-1]);		
		}
	}
	for(int i=1;i<=n;++i){
		int l=1,r=min(i,n-i+1),p=0;
		while(l<r){
			int mid=(l+r)>>1;
			auto [x,y]=Query(i-mid,i+mid);
			if(x<y){
				p=mid,l=mid+1;	
			}
			else{
				r=mid;
			}
		}
		mx=max(mx,p);
		if(!p){
			ans[i]=a[i];continue;
		}
		auto [x,y]=Query(i-p,i+p);
		if(a[i]>=a[i-1]){
			ans[i]=(p&1?x:y);	
		}
		else{
			ans[i]=(p&1?y:x);
		}
	}
	printf("%d\n",mx);
	for(int i=1;i<=n;++i){
		printf("%d ",ans[i]);
	}
	return 0;
}