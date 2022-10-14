#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re //register
#define LL inline ll
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	rnt _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=1e6+1;
int n,tot;
int a[N],b[N],c[N],tag[N],pri[N];
ll sum,ans;
V input(){n=getint();FOR(i,1,n)a[i]=getint(),sum+=a[i];}
V init(){
	FOR(i,1,n)c[i]=a[i];
	FOR(i,2,N-2){
		if(!tag[i])pri[++tot]=i;
		FOR(j,1,tot){
			if(1ll*i*pri[j]>=N)break;
			tag[pri[j]*i]=1;
			if(i%pri[j]==0)break;
		}
	}
}
LL once(ll k){
	rnt p=1,cur=1;
	ll sl,sr,dis,now,res=sum/k,tmp,out=0;
	FOR(i,1,n)a[i]=c[i],b[i]=0,res-=a[i]/k,a[i]%=k;
	while(res--){
		p=cur,sl=sr=dis=now=0;
		while(now<k){
			while(now+a[cur]<k){
				b[cur]=a[cur],now+=a[cur];
				dis+=1ll*(cur-p)*b[cur];
				a[cur++]=0;
			}
			tmp=k-now,a[cur]-=tmp,now+=tmp,b[cur]=tmp;
			dis+=1ll*(cur-p)*b[cur];
		}
		sl=0,sr=now-b[p];
		while(sl+b[p]<sr)
			sl+=b[p],dis+=sl-sr,sr-=b[++p];
		out+=dis;
	}
	return out;
}
V work(){
	if(sum<=1)return void(cout<<"-1");
	ans=1ll<<62;
	FOR(i,1,tot)if(sum%pri[i]==0)
		ans=min(ans,once(pri[i]));
	ans=min(ans,once(sum));
	cout<<ans;
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}