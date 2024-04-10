#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
const int N=1e2+5,mod=1e9+7;
int n,R,p1,p2,p3,p4,sum,val[N];
I pw(int x){return x*x;}
V check(int&x){x-=mod,x+=x>>31&mod;}
V input(){scanf("%d%d%d%d%d",&R,&p1,&p2,&p3,&p4);}
I valid(int x,int y){return pw(R+1-x)+pw(R+1-y)<=pw(R);}
I Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
struct poly{
	int a[N];
	I&operator[](const int&x){return a[x];}
	poly operator+(const poly&u)const{
		static poly out;
		FOR(i,0,n)check(out[i]=u.a[i]+a[i]);
		return out;
	}
	poly operator*(const int&x)const{
		static poly out;
		FOR(i,0,n)out[i]=1ll*x*a[i]%mod;
		return out;
	}
	I calc(int out=0){FOR(i,0,n)check(out+=1ll*a[i]*val[i]%mod);return out;}
}f[N][N],t[N],one;
V init(){
	check(sum+=p1),check(sum+=p2),check(sum+=p3),check(sum+=p4),sum=Pow(sum,mod-2);
	p1=1ll*sum*p1%mod,p2=1ll*sum*p2%mod,p3=1ll*sum*p3%mod,p4=1ll*sum*p4%mod;
	n=R<<1|1,val[0]=1,one[0]=mod-1,p2=Pow(p2,mod-2);
	check(p1=mod-p1),check(p3=mod-p3),check(p4=mod-p4);
	FOR(i,1,n)FOR(j,1,n)if(valid(i,j)){f[i][j][i]=1;break;}
	FOR(j,1,n)FOR(i,1,n)if(valid(i,j)){
		if(!valid(i,j+1))t[i]=(f[i][j]+f[i+1][j]*p1+f[i-1][j]*p3+f[i][j-1]*p4+one)*p2;
		else f[i][j+1]=(f[i][j]+f[i+1][j]*p1+f[i-1][j]*p3+f[i][j-1]*p4+one)*p2;
	}
	FOR(i,1,n){
		int p=0;
		FOR(j,i,n)if(t[j][i])p=j;
		swap(t[i],t[p]);
		FOR(j,i+1,n)t[j]=t[j]+t[i]*Pow(t[i][i],mod-2,mod-t[j][i]);
	}
	ROF(i,n,1){
		check(val[i]=mod-Pow(t[i][i],mod-2,t[i][0]));
		ROF(j,i-1,1)check(t[j][0]+=1ll*t[j][i]*val[i]%mod),t[j][i]=0;
	}
}
V work(){cout<<f[R+1][R+1].calc();}
int main(){
	input();
	init();
	work();
	return 0;
}