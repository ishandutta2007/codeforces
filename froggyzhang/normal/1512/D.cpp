#include<bits/stdc++.h>
using namespace std;
#define N 200020
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
int T,n,a[N];
bool Solve(){
	n=read()+2;
	ll sum=0;
	for(int i=1;i<=n;++i){
		a[i]=read();
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		int p=(i==n?i-1:n);
		if(sum-a[p]-a[i]==a[p]){
			for(int j=1;j<=n;++j){
				if(i==j||j==p)continue;
				printf("%d ",a[j]);
			}	
			printf("\n");
			return true;
		}
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