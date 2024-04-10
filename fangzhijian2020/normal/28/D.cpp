#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int n,v,c,l,r,ans,f[100005],pre[100005],tmp[100005];
map<int,int>mp[200005];
int max(int x,int y){
	return f[x]<f[y]?y:x;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d%d%d",&v,&c,&l,&r);
		if(mp[l].find(r+c)!=mp[l].end()){
			f[i]=f[mp[l][r+c]]+v;pre[i]=mp[l][r+c];
			if(mp[l+c].find(r)!=mp[l+c].end())mp[l+c][r]=max(mp[l+c][r],i);
			else mp[l+c][r]=i;
		}
		else if(l==0){
			f[i]=v;pre[i]=0;
			if(mp[l+c].find(r)!=mp[l+c].end())mp[l+c][r]=max(mp[l+c][r],i);
			else mp[l+c][r]=i;
		}
		if(r==0)ans=max(ans,mp[l+c][r]);
	}
	while(ans){
		tmp[++tmp[0]]=ans;
		ans=pre[ans];
	}
	printf("%d\n",tmp[0]);
	for(int i=tmp[0];i;--i)printf("%d ",tmp[i]);
	return 0;
}