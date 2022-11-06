#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int Mxdt=100000,N=2000000,mod=998244353,base=2333333,inv=222430835;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p1=(p2=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int n,m,x,tot;map<int,int>mp;long long ans;
vector<int>vx[100005],vy[100005];
int main(){
	n=read();m=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			x=read();
			if(mp.find(x)==mp.end())mp[x]=++tot;
			vx[mp[x]].push_back(i);
			vy[mp[x]].push_back(j);
		}
	}
	for(int i=1;i<=tot;++i){
		sort(vx[i].begin(),vx[i].end());
		sort(vy[i].begin(),vy[i].end());
		long long sum=0;
		for(int j=0;j<vx[i].size();++j){
			ans+=1ll*vx[i][j]*j-sum;sum+=vx[i][j];
		}
		sum=0;
		for(int j=0;j<vy[i].size();++j){
			ans+=1ll*vy[i][j]*j-sum;sum+=vy[i][j];
		}
	}
	cout<<ans<<"\n";
	return 0;
}