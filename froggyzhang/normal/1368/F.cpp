#include<bits/stdc++.h>
using namespace std;
#define N 1234
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
int n,a[N],k,now;
set<int> s;
int main(){
	n=read();k=sqrt(n);
	while(now<n-k-(n-1)/k){
		printf("%d ",k);
		int res=k;
		for(int i=1;i<=n&&res;++i){
			if(i%k==1||a[i])continue;
			printf("%d ",i);
			a[i]=1,++now,--res;
		}
		printf("\n");
		fflush(stdout);
		int x=read();
		for(int i=0;i<k;++i){
			if(a[(x+i-1)%n+1])a[(x+i-1)%n+1]=0,--now;	
		}
	}
	printf("0\n");
	fflush(stdout);
	return 0;
}