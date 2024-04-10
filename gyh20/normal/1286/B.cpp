#include<bits/stdc++.h>
using namespace std;
#define re register
inline int read(){
	re int t=0,f=1;
	re char v=getchar();
	while(v<'0'||v>'9'){
		if(v=='-')f=-1;
	v=getchar();}
	while(v>='0'&&v<='9'){
		t=(t<<3)+(t<<1)+(v^48);
		v=getchar();
	}
	return t*f;
}
struct edge{
	int to,next;
}e[4002];
int head[2002],cnt;
struct value{
	int pos;
	double val;
}vv[2002];
inline bool cmp(re value x,re value y){
	return x.val<y.val;
}
double num[2002][2002];
inline void add(re int x,re int y){
	e[++cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt;}
int n,a,c[2002],m,rt,siz[2002];
bool ia;
double sss;
inline void dfs(re int x){
	for(re int i=head[x];i;i=e[i].next){
		dfs(e[i].to);
		if(ia)return;
		for(re int j=siz[x]+1;j<=siz[e[i].to]+siz[x];++j){
			num[x][j]=num[e[i].to][j-siz[x]];
		}
		siz[x]+=siz[e[i].to];
	}
	sort(num[x]+1,num[x]+siz[x]+1);
	if(c[x]>siz[x]){
		ia=1;
		puts("NO");
		return;
	}
	++siz[x];
	if(c[x]==0){
		if(siz[x]==1)num[x][siz[x]]=(rand()*rand()%1000000)+x;
		else num[x][siz[x]]=num[x][1]/2;
	}
	else if(c[x]==siz[x]-1){
		num[x][siz[x]]=(1e9+num[x][siz[x]-1])/2;
	}
	else num[x][siz[x]]=(num[x][c[x]]+num[x][c[x]+1])/2;
 
	vv[x].pos=x;
	vv[x].val=num[x][siz[x]];
}
int ans[2002];
int main(){
n=read();
srand((unsigned)time(NULL));
for(re int i=1;i<=n;++i){
	a=read();
	if(a==0)rt=i;
	else add(a,i);
	c[i]=read();
}
dfs(rt);
if(ia)return 0;
sort(vv+1,vv+n+1,cmp);
puts("YES");
/*
for(re int i=1;i<=n;++i){
	printf("%d %.4lf ",vv[i].pos,vv[i].val);
}*/
for(re int i=1;i<=n;++i)ans[vv[i].pos]=i;
for(re int i=1;i<=n;++i)printf("%d ",ans[i]);
}