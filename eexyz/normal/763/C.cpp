#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
#define int long long 
struct ecsy{
	ll x,y,a,b,c,T,n,p,ans;
	ll ksm(ll xx,ll yy){
		ll ret=1;
		while(yy){
			if(yy&1)ret*=xx,ret%=p;
			xx*=xx;
			yy>>=1;
			xx%=p;
		}
		return ret;
	}
	ll ksmm(ll xx,ll yy,ll c){
		ll ret1=1,ret2=0,qwq;
		while(c){
			if(c&1){
				qwq=ret1;
				ret1=ret1*xx+y*ret2%p*yy;
				ret2=qwq*yy+ret2*xx;
				ret1%=p;
				ret2%=p;
			}
			c>>=1;
			qwq=xx;
			xx=xx*xx+y*yy%p*yy;
			yy=2*qwq*yy;
			xx%=p;
			yy%=p;
		}
		return (ret1+p)%p;
	}
	int solve(int nn,int pp){
			n=nn;p=pp;
			if(n==0)return 0;
			if(ksm(n,(p-1)/2)==p-1)return -1;
			while(1){
				x=(rand()<<15|rand())%p;
				if(ksm((x*x-n+p)%p,(p-1)/2)==p-1){
					break;
				}
			}
			y=(x*x-n+p)%p;
			ans=ksmm(x,1,(p+1)/2);
			if(ans>p/2)ans=p-ans;
			return ans; 
	}
}aaa;
ll a[N],m,s1,s2,s,n;
int i,d,c[N],x;
ll ksm(ll x,ll y){ll ret=1;for(;y;y>>=1,x=x*x%m)if(y&1)ret=ret*x%m;return ret;}
main(){
	cin>>m>>n;
	for(i=1;i<=n;++i)cin>>a[i];
	if(m==n){cout<<"0 1";return 0;}
	if(n==1)return cout<<a[1]<<" 0",0;
	for(i=1;i<=n;++i)(s2+=a[i]*a[i])%=m,s1+=a[i];
	s1%=m;
	s=(s2*n%m-s1*s1%m+m)%m;
	s1=0;
	for(i=1;i<n;++i)s1+=i*i*(n-i)%m;
	s=s*ksm(s1%m,m-2)%m;
	if(n==m-1)d=1;
	else d=aaa.solve(s,m);
	if(d==-1||d==0)return cout<<-1,0;
	s=a[1];
	for(i=2;i<=n;++i){
		a[i]-=a[1]-m;
	}a[1]=0;
	for(i=1;i<=n;++i)a[i]=1ll*a[i]*ksm(d,m-2)%m;
	sort(a+1,a+n+1);
	for(i=1;i<=n;++i)if(a[i]<=n)c[a[i]]=1;
	for(i=1;i<=n;++i){
		if(!c[i]){x=i;s=(1ll*(i-1)*d%m+s)%m;break;} 
	}
	for(x=1;x<=n;++x){
		if(a[x]>=i&&a[x]<m-n+i)return cout<<-1,0;
	}
	cout<<s<<" "<<(m-d)%m<<'\n';
}