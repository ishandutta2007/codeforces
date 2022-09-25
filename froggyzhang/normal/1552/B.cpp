#include<bits/stdc++.h>
using namespace std;
#define N 50050
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
int T,n;
array<int,5> a[N];
inline bool cmp(int i,int j){
	int cnt=0;
	for(int k=0;k<5;++k)cnt+=a[i][k]<a[j][k];
	return cnt>=3;	
}
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		for(int j=0;j<5;++j){
			a[i][j]=read();
		}
	}
	int u=1;
	for(int i=2;i<=n;++i){
		if(!cmp(u,i))u=i;
	}
	for(int i=1;i<=n;++i){
		if(i==u)continue;
		if(!cmp(u,i)){
			printf("-1\n");return;
		}	
	}
	printf("%d\n",u);
}
int main(){
	T=read();
	while(T--)Solve();
	return 0;
}