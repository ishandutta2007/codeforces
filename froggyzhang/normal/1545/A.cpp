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
int T,a[N],cnt[N],n;
void Solve(){
	n=read();
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;++i){
		a[i]=read();
		if(i&1)++cnt[a[i]];	
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		if(i&1)--cnt[a[i]];	
	}
	for(int i=1;i<=100000;++i){
		if(cnt[a[i]]){
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}