#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 10000100
inline int read(){
	int x=0,f=1;
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
int n,a[500050],mx,d1[500050],d2[500050];
bool ntp[N];
int p[N>>2],pn,from[N];
void init(int n){
	ntp[1]=true;
	for(int i=2;i<=n;++i){
		if(!ntp[i])p[++pn]=i;
		for(int j=1;j<=pn&&p[j]*i<=n;++j){
			ntp[p[j]*i]=true;
			from[p[j]*i]=p[j];
			if(i%p[j]==0)break;
		}
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		mx=max(mx,a[i]);
	}
	init(mx);
	for(int i=1;i<=n;++i){
		if(!from[a[i]]){
			d1[i]=d2[i]=-1;continue;
		}
		int x=1,o=from[a[i]];
		while(a[i]%o==0){
			x*=o,a[i]/=o;
		}
		if(x>1&&a[i]>1){
			d1[i]=x,d2[i]=a[i];
		}
		else{
			d1[i]=d2[i]=-1;
		}
	}
	for(int i=1;i<=n;++i)printf("%d ",d1[i]);
	printf("\n");
	for(int i=1;i<=n;++i)printf("%d ",d2[i]);
	return 0;
}