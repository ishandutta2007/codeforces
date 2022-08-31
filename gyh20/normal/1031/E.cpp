#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[100022],ans,lmt;
struct node{int x,y;};
vector<node>Ans,cur;
inline void dfs(re int x,re int y,vector<node>&tmp){
	if(x==lmt+1){
		if(tmp.size()<cur.size())cur=tmp;
		return;
	}
	if(x+y+y>lmt){
		if(!a[x])dfs(x+1,1,tmp);
		return;
	}
	dfs(x,y+1,tmp);assert(x!=0);
	tmp.push_back((node){x,y});
	a[x]^=1,a[x+y]^=1,a[x+y+y]^=1;
	dfs(x,y+1,tmp);
	a[x]^=1,a[x+y]^=1,a[x+y+y]^=1;
	tmp.pop_back();
}
inline void dfs1(re int x,re int y,vector<node>&tmp){
	if(cur.size()<=2)return;
	if(x==lmt+1){
		if(tmp.size()<cur.size())cur=tmp;
		return;
	}
	if(x+y+y>min(n,lmt+4)){
		if(!a[x])dfs1(x+1,1,tmp);
		return;
	}
	dfs1(x,y+1,tmp);assert(x!=0);
	tmp.push_back((node){x,y});
	a[x]^=1,a[x+y]^=1,a[x+y+y]^=1;
	dfs1(x,y+1,tmp);
	a[x]^=1,a[x+y]^=1,a[x+y+y]^=1;
	tmp.pop_back();
}
int main(){
	n=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	re int pos=1;
	while(pos<=n-8){
		lmt=pos+5;vector<node>A;cur.resize(100),dfs1(pos,1,A);if(n>10)assert(cur.size()!=100);
		for(auto z:cur)Ans.push_back(z),a[z.x]^=1,a[z.x+z.y]^=1,a[z.x+z.y+z.y]^=1;pos+=6;
	}pos=max(1,n-8);lmt=n;vector<node>A;cur.resize(100),dfs(pos,1,A);
	if(cur.size()==100)return puts("NO"),0;
	for(auto z:cur)Ans.push_back(z);
	puts("YES");
	printf("%u\n",Ans.size());
	for(auto z:Ans)printf("%d %d %d\n",z.x,z.x+z.y,z.x+z.y+z.y);
}