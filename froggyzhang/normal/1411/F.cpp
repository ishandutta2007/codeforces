#include<bits/stdc++.h>
using namespace std;
#define N 1000100
const int mod=1e9+7;
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
int T,n,p[N],tot,a[N],vis[N];
inline int calc(int A,int B){
	int t=min(A,B);
	A-=t,B-=t;
	return t+A/3*2+B;
}
void Solve(){
	n=read();tot=0;
	for(int i=1;i<=n;++i){
		p[i]=read();vis[i]=a[i]=0;
	}
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		++tot;
		for(int u=i;!vis[u];u=p[u]){
			vis[u]=1;++a[tot];
		}
	}
	int ans=0;
	int num=1;
	if(n%3==0){
		for(int i=1;i<=n/3;++i)num=3LL*num%mod;
		int A=0,B=0;
		for(int i=1;i<=tot;++i){
			ans+=(a[i]-1)/3;
			if(a[i]%3==1)++A;
			else if(a[i]%3==2)++B;
		}
		ans+=calc(A,B);
	}
	else if(n%3==1){
		num=4;
		for(int i=1;i<=n/3-1;++i)num=3LL*num%mod;
		int flag=0;
		int A=0,B=0;
		int tmp=0;
		for(int i=1;i<=tot;++i){
			tmp+=(a[i]-1)/3;
			if(a[i]%3==1)++A;
			else if(a[i]%3==2)++B;
			if(a[i]%3==1&&a[i]>=4)flag=1;
		}
		ans=n*233;
		if(flag)ans=min(ans,calc(A-1,B)-1);
		if(B>=2)ans=min(ans,calc(A,B-2));
		if(B>=1&&A>=2)ans=min(ans,calc(B-1,A-2)+1);
		if(A>=4)ans=min(ans,calc(A-4,B)+2);
		if(A>=1)ans=min(ans,calc(A-1,B)+1);
		ans+=tmp;
	}
	else{
		num=2;
		for(int i=1;i<=n/3;++i)num=3LL*num%mod;
		int A=0,B=0;
		for(int i=1;i<=tot;++i){
			ans+=(a[i]-1)/3;
			if(a[i]%3==1)++A;
			else if(a[i]%3==2)++B;	
		}
		if(B)--B;
		else ++ans,A-=2;
		ans+=calc(A,B);
	}
	printf("%d %d\n",num,ans);
}
int main(){
	T=read();
	while(T--)Solve();
	return 0;
}