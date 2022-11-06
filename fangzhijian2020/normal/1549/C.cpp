#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,m,Q,vis[200005],ans,opt,x,y;set<int>s[200005];
set<int>::iterator it;
void add(int x){
	if(vis[x]){vis[x]=0;++ans;}
}
void del(int x){
	if(!vis[x]){vis[x]=1;--ans;}
}
bool check(int x){
	if(s[x].empty())return 0;
	it=s[x].end();--it;
	if((*it)>x)return 1;
	return 0;
}
int main(){
	ans=n=read();m=read();
	for(int i=1;i<=m;++i){
		x=read();y=read();
		s[x].insert(y);
		s[y].insert(x);
		if(x>y)del(y);
		if(y>x)del(x);
	}
	Q=read();
	for(int i=1;i<=Q;++i){
		opt=read();
		if(opt==1){
			x=read();y=read();
			s[x].insert(y);
			s[y].insert(x);
			if(check(x))del(x);
			if(check(y))del(y);
		}
		else if(opt==2){
			x=read();y=read();
			s[x].erase(y);
			s[y].erase(x);
			if(!check(x))add(x);
			if(!check(y))add(y);			
		}
		else if(opt==3){
			cout<<ans<<"\n";
		}
	}
	return 0;
}