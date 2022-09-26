#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int len=30;
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
int n,T,L[N],R[N],blocks,t[N],pos[N];
inline int Ask(int l,int r){
	printf("? %d %d\n",l,r);
	fflush(stdout);
	return read();
}
void Report(int x){
	printf("! %d\n",x);
	fflush(stdout);	
}
int Solve(int k){
	int p=1;
	while(k>R[p]-t[p])++p;
	int l=L[p],r=R[p]+1,ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(mid-Ask(1,mid)>=k){
			ans=r=mid;
		}
		else{
			l=mid+1;
		}
	}
	return ans;
}
void init(){
	blocks=n/len;
	if(n%len)++blocks;
	for(int i=1;i<=blocks;++i){
		L[i]=(i-1)*len+1,R[i]=min(i*len,n);
		for(int j=L[i];j<=R[i];++j){
			pos[j]=i;
		}
	}
	for(int i=1;i<=blocks;++i){
		t[i]=Ask(1,R[i]);
	}
}
int main(){
	n=read(),T=read();
	while(T--){
		int k=read();
		if(!blocks)init();
		int x=Solve(k);
		Report(x);
		for(int i=pos[x];i<=blocks;++i)++t[i];
	}
	return 0;
}