#include<bits/stdc++.h>
using namespace std;
#define V inline void
#define VI vector<int>
#define ll long long int
#define FOR(i,a,b) for(int i=a;i<b;i++)
const int N=18,sgn[]={1,-1};
int n,l,a[N][N],cnt[1<<N],tag[1<<N];
ll dp[N][1<<N],g[N+1][1<<N],t[N+1][1<<N],f[1<<N];
map<VI,ll>mp;
V input(){
	static char tmp[N];
	scanf("%d",&n),l=1<<n;
	FOR(i,0,n){
		scanf("%s",tmp),dp[i][1<<i]=1;
		FOR(j,0,n)a[i][j]=tmp[j]-'0';
	}
}
V dot(ll*a,ll*b,ll*c){FOR(i,0,l)c[i]=a[i]*b[i];}
V FWT(ll*t){for(int i=1;i<l;i<<=1)FOR(j,0,l)if(j&i)t[j]+=t[j^i];}
V IFWT(ll*t){for(int i=1;i<l;i<<=1)FOR(j,0,l)if(j&i)t[j^i]-=t[j];}
V init(){
	tag[0]=sgn[n&1];
	FOR(i,1,l)cnt[i]=cnt[i>>1]+(i&1),tag[i]=sgn[i&1]*tag[i>>1],t[0][i]=1;
	FOR(i,1,l)FOR(j,0,n)FOR(k,0,n)if(!(i>>k&1)&&a[j][k])dp[k][1<<k|i]+=dp[j][i];
	FOR(i,0,n)FOR(j,1,l)g[cnt[j]][j]+=dp[i][j];
	FOR(i,1,n)FWT(g[i]);
}
V dfs(int p,int lim,int res){
	static VI now;
	if(!res){
		ll sum=0;
		FOR(i,0,l)sum+=t[p][i]*tag[i];
		return void(mp[now]=sum);
	}
	FOR(i,lim,res+1)dot(t[p],g[i],t[p+1]),now.push_back(i),dfs(p+1,i,res-i),now.pop_back();
}
ll div(int x){
	VI now;int cnt=1;
	FOR(i,0,n)(~x>>i&1)&&(now.push_back(cnt),cnt=0),cnt++;
	return now.push_back(cnt),sort(now.begin(),now.end()),mp[now];
}
V work(){
	dfs(0,1,n--),l>>=1;
	FOR(i,0,l)f[i]=div(i);
	IFWT(f);
	FOR(i,0,l)cout<<f[i]<<' ';
}
int main(){
	input();
	init();
	work();
	return 0;
}