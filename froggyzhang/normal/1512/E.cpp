#include<bits/stdc++.h>
using namespace std;
#define N 505
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
int T,n,l,r,s,a[N],vis[N];
bool Solve(){
	n=read(),l=read(),r=read(),s=read();
	int k=r-l+1;
	int L=k*(k+1)/2,R=(n+n-k+1)*k/2;
	if(s>=L&&s<=R){
		for(int i=1;i<=n+1;++i)vis[i]=a[i]=0;
		for(int i=l;i<=r;++i){
			a[i]=i-l+1;
			s-=i-l+1;
		}
		int i=r;
		while(s--){
			if(a[i]==n||a[i]+1==a[i+1])--i;
			++a[i];
		}
		for(int i=l;i<=r;++i)vis[a[i]]=1;
		for(int i=1,j=1;i<=n;++i){
			if(i<l||i>r){
				while(vis[j])++j;
				a[i]=j;
				++j;	
			}
		}
		for(int i=1;i<=n;++i){
			printf("%d ",a[i]);
		}
		printf("\n");
		return true;
	}
	return false;
}
int main(){
	T=read();
	while(T--){
		if(!Solve())printf("-1\n");
	}
	return 0;
}