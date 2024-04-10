#include<bits/stdc++.h>
using namespace std;
#define rnt re int
#define re //register
#define I inline int
#define V inline void
#define B inline bool
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	rnt _s=0;re char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=2e5+1;
int n,k,lim,tot;
int a[N],tag[N];
int mp[N],pw[N];
ll ans;
int m=N-1;
V input(){
	n=getint(),k=getint();
	FOR(i,1,n)a[i]=getint();
}
V init(){
	lim=pow(m,1.0/k);
	tag[1]=1;
	FOR(i,2,m)if(!tag[i])
		FOR(j,2,m/i)tag[i*j]=1;
}
I turn(rnt x){
	ll out=1,cnt=0;
	rnt len=sqrt(x);
	FOR(i,1,len)if(!tag[i]&&x%i==0){
		cnt=k;
		while(x%i==0)cnt--,x/=i;
		FOR(j,1,cnt){
			out*=i;
			if(out>=N)
				return 0;
		}
	}
	if(x){
		cnt=k-1;
		FOR(j,1,cnt){
			out*=x;
			if(out>=N)
				return 0;
		}
		
	}
	return out;
}
I Pow(ll t,rnt x){
	ll s=1;
	while(x){
		if(x&1)s=s*t;
		t=t*t,x>>=1;
	}
	return s;
}
B check(ll x){
	re ll tmp=cbrt(x);
	return tmp*tmp*tmp==x;
}
V fen(rnt x){
	FOR(i,2,x){
		while(x%i==0)
			cout<<i<<'\n',x/=i;
	}
}
V work(){
	FOR(i,1,lim)pw[i]=Pow(i,k);
	FOR(i,1,n)FOR(j,1,lim)if(!tag[j])
		while(a[i]%pw[j]==0)
			a[i]/=pw[j];
//	FOR(i,1,n)
//		cout<<a[i]<<' '<<turn(a[i])<<'\n';
//	turn(3481);
//	cout<<turn(3481)<<'\n';
//	fen(3481);
	FOR(i,1,n){
		rnt x=turn(a[i]);
//		cout<<mp[x]<<'\n';
		ans+=mp[x];
		mp[a[i]]++;
		
	}
	cout<<ans;
//	cerr<<ans<<'\n';
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
//	freopen("test.ans","w",stdout);
	input();
	init();
	work();
//	cout<<'\n';
//	ans=0;
//	FOR(i,1,n){
//		if(i%100==0)
//			cerr<<i<<'\n';
//		FOR(j,i+1,n)
//			if(check(1ll*a[i]*a[j]))
//				ans++;
//	}
//	cout<<'\n'<<ans;
//	cerr<<ans;
	return 0;
}