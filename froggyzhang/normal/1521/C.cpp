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
int p[N],T,n;
inline int Ask(int t,int i,int j,int x){
	printf("? %d %d %d %d\n",t,i,j,x);
	fflush(stdout);
	return read();
}
void Solve(){
	n=read();
	int pos=n;
	for(int i=1;i<n;i+=2){
		int d=Ask(2,i,i+1,1);
		if(d==1){
			pos=i;break;
		}
		else if(d==2){
			if(Ask(2,i+1,i,1)==1){
				pos=i+1;
				break;
			}	
		}
	}
	p[pos]=1;
	for(int i=1;i<=n;++i){
		if(i==pos)continue;
		p[i]=Ask(1,pos,i,n-1);
	}
	printf("!");
	for(int i=1;i<=n;++i){
		printf(" %d\n",p[i]);
	}
	fflush(stdout);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}