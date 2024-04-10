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
#define N 233
int T,n,a[N];
void Solve(){
	n=read();
	int x=read(),sum=0;
	for(int i=1;i<=n;++i){
		a[i]=read();
		sum+=a[i];
	}
	if(sum==x){
		printf("NO\n");
		return;
	}
	printf("YES\n");
	sum=0;
	for(int i=1;i<n;++i){
		sum+=a[i];
		if(sum==x){
			swap(a[i],a[i+1]);
			break;
		}
	}
	for(int i=1;i<=n;++i){
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}