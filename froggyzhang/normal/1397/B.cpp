#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 100010
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
int n,a[N];
ll ans;
ll Abs(ll x){
	return x>=0?x:-x;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	if(n>50){
		for(int i=1;i<=n;++i){
			ans+=a[i]-1;
		}
	}
	else{
		ans=1e18;
		for(int p=1;p<=100000;++p){
			ll now=1,tot=0;
			for(int i=1;i<=n;++i){
				if(now>1e13){
					tot+=1e18;
					break;
				}
				tot+=Abs(now-a[i]);
				now*=p;
			}
			ans=min(ans,tot);
		}
	}
	cout<<ans<<endl;
	return 0;
}