#include<bits/stdc++.h>
using namespace std;
#define N 1000100
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
int n,p[N],a[N],b[N],vis[N];
ll s1[N],s2[N];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		s1[i]=s1[i-1]+(a[i]=read());
	}
	for(int i=1;i<=n;++i){
		s2[i]=s2[i-1]+(b[i]=read());
	}
	bool flag=false;
	if(s1[n]>s2[n])swap(s1,s2),swap(a,b),flag=true;
	memset(vis,-1,sizeof(vis)); 
	for(int i=0,j=0;i<=n;++i){
		while(s2[j]<s1[i])++j;
		p[i]=j;
		int x=s2[j]-s1[i];
		if(~vis[x]){
			if(!flag){
				printf("%d\n",i-vis[x]);
				for(int k=vis[x]+1;k<=i;++k)printf("%d ",k);
				printf("\n");
				printf("%d\n",j-p[vis[x]]);
				for(int k=p[vis[x]]+1;k<=j;++k)printf("%d ",k);
				printf("\n");
			}
			else{
				printf("%d\n",j-p[vis[x]]);
				for(int k=p[vis[x]]+1;k<=j;++k)printf("%d ",k);
				printf("\n");
				printf("%d\n",i-vis[x]);
				for(int k=vis[x]+1;k<=i;++k)printf("%d ",k);
				printf("\n");
			}
			return 0;
		}
		vis[x]=i;
	}
	return 0;
}