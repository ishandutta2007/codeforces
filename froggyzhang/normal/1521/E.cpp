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
int T,m,k,a[N],c[1234][1234],p[N];
inline bool check(int n){
	return n*n-(n>>1)*(n>>1)>=m && n*((n+1)>>1)>=a[p[1]];	
}
void Solve(){
	m=read(),k=read();
	for(int i=1;i<=k;++i){
		a[i]=read();
		p[i]=i;
	}
	sort(p+1,p+k+1,[&](int i,int j){return a[i]>a[j];});
	int n=1;
	while(!check(n))++n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			c[i][j]=0;
		}
	}
	static vector<pair<int,int> > pos;
	pos.clear();
	for(int i=1;i<=n;i+=2){
		for(int j=2;j<=n;j+=2){
			pos.emplace_back(i,j);
		}
	}
	for(int i=1;i<=n;i+=2){
		for(int j=1;j<=n;j+=2){
			pos.emplace_back(i,j);
		}
	}
	for(int i=2;i<=n;i+=2){
		for(int j=1;j<=n;j+=2){
			pos.emplace_back(i,j);
		}
	}
	reverse(pos.begin(),pos.end()); 
	for(int t=1;t<=k;++t){
		int x=p[t];
		while(a[x]--){
			c[pos.back().first][pos.back().second]=x;
			pos.pop_back();
		}
	}
	printf("%d\n",n);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}