#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int Mxdt=100000,N=200000,mod=998244353;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int Mod(int x){return x<mod?x:x-mod;}
void Add(int&x,int y){x=Mod(x+y);}
int k,A,h,rk[10005],f[10005],S,tot,now,ans[10005];
map<int,int>mp0,mp1;
int solve(int l,int r,int dep){
	if(l==r){return l;}
	int mid=l+r>>1;
	int t1=solve(l,mid,dep+1);
	int t2=solve(mid+1,r,dep+1);
	int opt=(S>>tot)&1;++tot;
	if(!opt){
		Add(now,1ll*t1*f[rk[dep]]%mod);
		return t2;
	}
	else{
		Add(now,1ll*t2*f[rk[dep]]%mod);
		return t1;
	}
}
int cal(int l,int r,int dep){
	if(l==r){return l;}
	int mid=l+r>>1;
	int t1=cal(l,mid,dep+1);
	int t2=cal(mid+1,r,dep+1);
	int opt=(S>>tot)&1;++tot;
	if(!opt){
		ans[t1]=rk[dep];
		return t2;
	}
	else{
		ans[t2]=rk[dep];
		return t1;
	}
}
void output(int s1,int s2,int opt){
	tot=0;S=s1;
	int t1=cal(1,1<<k-1,2);
	tot=0;S=s2;
	int t2=cal((1<<(k-1))+1,1<<k,2);
	if(!opt){ans[t1]=1;ans[t2]=2;}
	else{ans[t1]=2;ans[t2]=1;}
	for(int i=1;i<=(1<<k);++i)cout<<ans[i]<<" ";
}
int main(){
	k=read();A=read();h=read();
	rk[0]=1;rk[1]=2;
	for(int i=1;i<=k+1;++i){
		rk[i+1]=rk[i]+(1<<i-1);
	}
	f[0]=1;
	for(int i=1;i<=rk[k+2];++i){
		f[i]=1ll*f[i-1]*A%mod;
	}
	for(int i=0;i<(1<<((1<<k-1)-1));++i){
		S=i;tot=now=0;int w=solve(1,1<<k-1,2);
		int tmp=(now+1ll*w*f[rk[1]]%mod)%mod;
		
		mp1[tmp]=S;
		tmp=(now+1ll*w*f[rk[0]]%mod)%mod;
		mp0[tmp]=S;
	}
	for(int i=0;i<(1<<((1<<k-1)-1));++i){
		S=i;tot=now=0;int w=solve((1<<(k-1))+1,1<<k,2);
		int tmp=(now+1ll*w*f[rk[1]]%mod)%mod;
		if(mp0.find(Mod(h-tmp+mod))!=mp0.end()){
			output(mp0[Mod(h-tmp+mod)],S,0);return 0;
		}
		tmp=(now+1ll*w*f[rk[0]]%mod)%mod;
		if(mp1.find(Mod(h-tmp+mod))!=mp1.end()){
			output(mp1[Mod(h-tmp+mod)],S,1);return 0;
		}
	}
	puts("-1");	
	return 0;
}