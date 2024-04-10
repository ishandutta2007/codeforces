#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,int>m[2][28];
ll f[20];
int a[28];
int n,k;
ll r;
void dfs(ll now,int nowk,int x,int end,void(*work)(ll,int)){
	if(now>r)return;
	if(nowk>k)return;
	if(x==end+1){
		work(now,nowk);
		return;
	}
	dfs(now,nowk,x+1,end,work);
	dfs(now+a[x],nowk,x+1,end,work);
	if(a[x]<20)dfs(now+f[a[x]],nowk+1,x+1,end,work);
}
void work1(ll a,int k){
	if(m[0][k].count(a))
		m[0][k][a]++;
	else m[0][k][a]=1;
}
void work2(ll a,int k){
	if(m[1][k].count(a))
		m[1][k][a]++;
	else m[1][k][a]=1;
}
void add(map<ll,int>& a,map<ll,int>& b){
	for(auto i:b){
		if(a.count(i.first))
			a[i.first]+=i.second;
		else a[i.first]=i.second;
	}
}
int main(){
	scanf("%d%d%I64d",&n,&k,&r);
	f[1]=1;
	for(int i=2;i<20;i++)f[i]=f[i-1]*i;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	k=min(k,n);
	int mid=n>>1;
	dfs(0,0,1,mid,work1);
	dfs(0,0,mid+1,n,work2);
	for(int i=1;i<=k;i++)add(m[0][i],m[0][i-1]);
	ll ans=0;
	for(int i=0;i<=k;i++){
		for(auto j:m[1][i]){
			if(m[0][k-i].count(r-j.first))
				ans+=m[0][k-i][r-j.first]*j.second;
		}
	}
	return printf("%I64d",ans),0;
}