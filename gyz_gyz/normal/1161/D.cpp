#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef vector<int>ve;
const int N=1e5+10;
const int mo=998244353;
const int inf=1e9;
int n,m,ans,f[N],nw[N];
bool g[N];char s[N];
int gf(int x){
	if(f[x]==x)return x;
	gf(f[x]);g[x]^=g[f[x]];
	return f[x]=f[f[x]];
}
bool lk(int x,int y,bool z){
	gf(x);gf(y);z^=g[x]^g[y];
	if(f[x]==f[y])return !z;
	if(nw[f[y]]==2){
		f[f[y]]=f[x];g[f[y]]=z;
	}else if(nw[f[x]]==2){
		f[f[x]]=f[y];g[f[x]]=z;
	}else{
		if((nw[f[x]]^nw[f[y]])!=z)return 0;
		f[f[y]]=f[x];g[f[y]]=z;
	}
	return 1;
}
int sol(){
	rep(i,1,n+m)f[i]=i,g[i]=0,nw[i]=2;
	rep(i,1,n-m)if(s[i]!='?')nw[i]=s[i]-'0';
	nw[n+1]=1;
	rep(i,1,n/2)if(!lk(i,n-i+1,0))return 0;
	rep(i,1,m/2)if(!lk(n+i,n+m-i+1,0))return 0;
	rep(i,0,m-1)if(s[n-i]!='?'){
		if(!lk(n-i,n+m-i,s[n-i]-'0'))return 0;
	}
	int res=1;
	rep(i,1,n+m)if(gf(i)==i&&nw[i]==2)res=res*2%mo;
	return res;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(m=1;m<n;++m)ans=(ans+sol())%mo;
	printf("%d\n",ans);
}