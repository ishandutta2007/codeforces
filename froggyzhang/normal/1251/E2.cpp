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
int T,n;
array<int,2> a[N];
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i][0]=read(),a[i][1]=read();
	}
	sort(a+1,a+n+1,greater<array<int,2> >());
	priority_queue<int,vector<int>,greater<int> > q;
	ll ans=0;
	for(int t=n,j=1;t>=1;--t){
		while(j<=n&&a[j][0]==t){
			q.push(a[j][1]);
			++j;
		}
		while((int)q.size()>n-t){
			ans+=q.top();
			q.pop();	
		}	
	}
	printf("%lld\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();	
	}
	return 0;
}