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
int n,a[N];
vector<int> p[N];
int main(){
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=n;i>=1;--i){
		p[a[i]].push_back(i);
	}
	int x=0,y=0,ans=0;
	for(int i=1;i<=n;++i){
		int lx=p[x].empty()?n+1:p[x].back();
		int ly=p[y].empty()?n+1:p[y].back();
		if(x==a[i])lx=n+2;
		if(y==a[i])ly=n+2;
		if(lx<=ly){
			ans+=(x!=a[i]);
			x=a[i];
		}
		else{
			ans+=(y!=a[i]);
			y=a[i];
		}
		p[a[i]].pop_back();
	}
	printf("%d\n",ans);
	return 0;
}