#include<bits/stdc++.h>
using namespace std;
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
int n,T;
inline int Ask(int l,int r){
	printf("? %d %d\n",l,r);
	fflush(stdout);
	return read();
}
void Report(int x){
	printf("! %d\n",x);
	fflush(stdout);	
}
int main(){
	n=read(),T=read();
	int k=read();
	int l=1,r=n+1,ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(mid-Ask(1,mid)>=k){
			ans=r=mid;
		}
		else{
			l=mid+1;
		}
	}
	Report(ans);
	return 0;
}