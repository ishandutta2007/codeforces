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
int T,n,cnt[3];
void Solve(){
	n=read();
	cnt[0]=cnt[1]=cnt[2]=0;
	for(int i=1;i<=n;++i){
		++cnt[read()%3];
	}
	printf("%d\n",max(cnt[1]-cnt[0],max(cnt[2]-cnt[1],cnt[0]-cnt[2])));
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;	
}