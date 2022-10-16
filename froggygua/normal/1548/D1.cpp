#include<bits/stdc++.h>
using namespace std;
#define N 6006
typedef long long ll;
typedef unsigned long long ull;
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
int n;
struct Point{
	int x,y;	
}p[N];
ull d[N][N/64+5];
ll ans;
int cnt[4];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		p[i].x=read()/2,p[i].y=read()/2;
		++cnt[(p[i].x%2)*2+p[i].y%2];
	}
	ll ans=1LL*n*(n-1)*(n-2)/6;
	for(int i=0;i<4;++i)
		for(int j=i+1;j<4;++j)
			for(int k=j+1;k<4;++k)
				ans-=1LL*cnt[i]*cnt[j]*cnt[k];
	printf("%lld\n",ans);
	return 0;
}