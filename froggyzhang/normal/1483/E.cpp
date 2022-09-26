#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll lim=1e14;
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
//#define mak mydd
int T;
char s[20];
int qcnt;
ll M;
inline bool Ask(ll x){
	++qcnt;
	if(qcnt>105)exit(0);
	printf("? %lld\n",x);
	fflush(stdout);
	#ifdef mak
		return x<=M;
	#endif
	scanf("%s",s);
	return s[0]=='L';
}
inline void Report(ll x){
	printf("! %lld\n",x);
	fflush(stdout);	
}
void Solve(){
	#ifdef mak
		M=read();
	#endif
	
	qcnt=0;
	ll now=1;
	while(Ask(now)){
		if(now==lim){Report(lim);return;}
		now=min(lim,now<<1);
	}
	ll l=(now>>1)+1,r=now,ans=(now>>1);
	now=0;
	int z=0;
	while(l<r){
		ll mid=(l*3+r*(z+1))/(z+4);
		while(now<mid)now+=ans,Ask(ans);
		if(Ask(mid)){
			l=mid+1,ans=mid,now+=mid;++z;
		}
		else{
			r=mid,now-=mid;z=max(z-1,0);
		}
	}
	Report(ans);
	
	#ifdef mak
		cerr<<" Querys: "<<qcnt<<endl;
	#endif
}
int main(){
	T=read();
	while(T--){
		Solve();	
	}
	return 0;
}