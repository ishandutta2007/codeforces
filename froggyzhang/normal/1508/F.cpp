#include<bits/stdc++.h>
using namespace std;
#define N 25005
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
int n,m,a[N],prel[N],sufl[N],prer[N],sufr[N]; 
int L[N],R[N],ans;
void Solve(int l,int r){
	for(int i=l;i<=r;++i){
		for(int &j=R[i];j<=r;++j){
			if(a[j]>a[i]){
				int &k=sufr[i];
				if(a[j]<a[k]){
					ans+=(prel[j]==i)-(prel[k]==i);
					k=j;	
				}
			}	
			else{
				int &k=prer[i];
				if(a[j]>a[k]){
					ans+=(sufl[j]==i)-(sufl[k]==i);
					k=j;	
				}
			}
		}
		for(int &j=L[i];j>=l;--j){
			if(a[j]>a[i]){
				int &k=sufl[i];
				if(a[j]<a[k]){
					ans+=(prer[j]==i)-(prer[k]==i);
					k=j;	
				}
			}	
			else{
				int &k=prel[i];
				if(a[j]>a[k]){
					ans+=(sufr[j]==i)-(sufr[k]==i);
					k=j;	
				}
			}
		}	
	}	
}
int main(){
	n=read(),m=read();
	a[0]=n+1;
	for(int i=1;i<=n;++i){
		a[i]=read();
		L[i]=i-1;
		R[i]=i+1;
		sufl[i]=sufr[i]=0;
		prel[i]=prer[i]=n+1;
	}
	while(m--){
		int l=read(),r=read();
		Solve(l,r);
		printf("%d\n",ans);
	} 
	return 0;
}