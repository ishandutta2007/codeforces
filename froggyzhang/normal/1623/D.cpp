#include<bits/stdc++.h>
using namespace std;
#define N 400010
typedef long long ll;
const int mod=1e9+7;
int n,m,sx,sy,tx,ty,p;
bool a[N];
int tot;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
const int inv100=qpow(100,mod-2);
map<tuple<int,int,int>,int> mp;
void Solve(){
	cin>>n>>m>>sx>>sy>>tx>>ty>>p;
	p=1LL*(mod+100-p)*inv100%mod;
	int nx=sx,ny=sy,dx=1,dy=1;
	tot=0;
	mp.clear();
	int pos=0;
	while(true){
		if(nx+dx<1||nx+dx>n)dx=-dx;
		if(ny+dy<1||ny+dy>m)dy=-dy;
		auto tp=make_tuple(nx,ny,dx*2+dy);
		if(mp.count(tp)){
			pos=mp[tp];break;
		}
		a[++tot]=nx==tx||ny==ty;
		nx+=dx,ny+=dy;
		mp[tp]=tot;
	};
	int ans=0,cir=1,pre=1,zz=0;
	for(int i=1;i<pos;++i){
		if(a[i])pre=1LL*pre*p%mod;
		zz=(zz+pre)%mod;
	}
	for(int i=pos;i<=tot;++i){
		if(a[i])cir=1LL*cir*p%mod;
		ans=(ans+cir)%mod;
	}
	ans=(zz+1LL*ans*pre%mod*qpow(mod+1-cir,mod-2))%mod;
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}