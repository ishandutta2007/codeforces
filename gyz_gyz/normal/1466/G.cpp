#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e5+10;
const int M=2e6+10;
const int mo=1e9+7;
const ll inf=1e18;
ll nh[M],mh[M],pw[M],v[N][26],p2[N],ny[N];;
char s0[110],s1[N],s[M],t[M];
ll cn(int l,int r,int w){
	return (nh[r]-nh[l-1])*pw[w-r];
}
ll cm(int l,int r,int w){
	return (mh[r]-mh[l-1])*pw[w-r];
}
int main(){int len,q;
	scanf("%d%d%s%s",&len,&q,s0+1,s1+1);
	int n0=strlen(s0+1);
	pw[0]=p2[0]=ny[0]=1;
	rep(i,1,len){
		p2[i]=p2[i-1]*2%mo;
		ny[i]=ny[i-1]*((mo+1)/2)%mo;
	}
	rep(i,1,M-1)pw[i]=pw[i-1]*313;
	rep(i,1,len)rep(j,0,26)v[i][j]=(v[i-1][j]+(s1[i]==j+'a')*p2[len-i])%mo;
	rep(o,1,q){int k;
		scanf("%d%s",&k,t+1);
		int n=n0,m=strlen(t+1),nw=0;
		rep(i,1,n)s[i]=s0[i];
		while(n<m&&nw<k){
			rep(i,1,n)s[i+n+1]=s[i];
			s[n+1]=s1[++nw];n+=n+1;
		}
		if(n<m){
			printf("0\n");continue;
		}
		rep(i,1,n)nh[i]=nh[i-1]+s[i]*pw[i];
		rep(i,1,m)mh[i]=mh[i-1]+t[i]*pw[i];
		ll ans=0;
		rep(i,m,n)if(cn(i-m+1,i,i)==cm(1,m,i))ans=(ans+p2[k-nw])%mo;
		rep(i,1,m){
			if(i>1&&cn(n-i+2,n,n)!=cm(1,i-1,n))continue;
			if(i<m&&cn(1,m-i,m)!=cm(i+1,m,m))continue;
			int x=t[i]-'a';
			ans=(ans+(v[k][x]+mo-v[nw][x])*ny[len-k])%mo;
		}
		printf("%lld\n",ans);
	}
}