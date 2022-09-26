#include<bits/stdc++.h>
using namespace std;
#define N 100010
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
int n,k,a[N],b[N],p;
inline int Ask(int x){
	printf("? %d\n",x);
	fflush(stdout);
	return read();
}
void Report(int x){
	printf("! %d\n",x);
	fflush(stdout);
	exit(0);
}
void Find(int l,int r){
	while(true){
		int mid=(l+r)>>1;
		int t=Ask((mid-1+n)%n+1);
		if(t==k){
			Report((mid-1+n)%n+1);
		}
		if(t<k)l=mid+1;
		else r=mid;
	}
}
int main(){
	srand(time(0));
	n=read(),k=read();
	int sq=sqrt(n);
	int len=n/sq;
	for(int i=1;i<=sq;++i)Ask(1);
	while(true){
		int pos=(1LL*rand()*rand()+rand())%n+1;
		int t=Ask(pos);
		if(t^k){
			if(t<k)Find(pos,pos+len);
			else Find(pos-len,pos);
		}
	}
	return 0;
}