#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
int h,q,up;
map<int,int> mp;
char opt[10];
double dfs(int u,int mx){
	if(mx>=mp[u])return mx;
	if(u>=up)return mp[u];
	return 0.5*dfs(u<<1,max(mx,mp[u]-mp[u<<1]))+0.5*dfs(u<<1|1,max(mx,mp[u]-mp[u<<1|1]));
}
void rd(int &x){x=0;char ch=getchar();while(ch<'0'||ch>'9')ch=getchar();while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}}
int main(){
	rd(h);rd(q);
	up=1<<h;
	int v,e;
	for(int i=1;i<=q;++i){
		scanf("%s",opt);
		if(opt[0]=='a'){
			rd(v);rd(e);
			while(v){
				mp[v]=mp[v]+e;
				v/=2;
			}
		}else printf("%.4lf\n",dfs(1,0));
	}
	return 0;
}