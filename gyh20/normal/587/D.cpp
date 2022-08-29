#include<bits/stdc++.h>
#define re register
using namespace std;
const int Mxdt=100000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline char pc(char ch,bool bj){
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
void print(int x)
{
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline void printnum(int x,char ch)
{
	print(x),pc(ch,false);
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int n,head[600002],cnt,lst[600002],w[600002],dfn[600002],low[600002],stk[600002],bl[600002],tim,tp,blk,tot,head1[600002],m,cnt1,a[600002],b[600002],c[600002],d[600002],A[600002],B[600002];
char ist[600002];
struct edge{int to,next;}e[20000002];
struct node{int x,y,id;};
vector<node>v[50002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void tj(re int x){
	dfn[x]=low[x]=++tim,stk[++tp]=x,ist[x]=1;
	for(re int i=head[x];i;i=e[i].next)
		if(!dfn[e[i].to])tj(e[i].to),low[x]=min(low[x],low[e[i].to]);
		else if(ist[e[i].to])low[x]=min(low[x],dfn[e[i].to]);
	if(dfn[x]==low[x]){
		++blk;
		do{
			bl[stk[tp]]=blk;
			ist[stk[tp--]]=0;
		}while(stk[tp+1]^x);
	}
}
inline bool check(){
	memset(dfn,0,sizeof(dfn)),tim=0;
	for(re int i=1;i<=tot;++i)if(!dfn[i])tj(i);
	for(re int i=1;i<=m;++i)if(bl[i]==bl[i+m])return 0;
	return 1;
}
inline bool check(re int x){
	for(re int i=1;i<=tot;++i)head[i]=head1[i];cnt=cnt1;
	for(re int i=1;i<=m;++i)if(d[i]>x)add(i,i+m);
	return check();
}
signed main(){
	//freopen("a.in","r",stdin);
	n=read(),m=tot=read(),tot<<=1;
	for(re int i=1;i<=m;++i)a[i]=read(),b[i]=read(),c[i]=A[i]=read(),d[i]=B[i]=read();
	sort(A+1,A+m+1),sort(B+1,B+m+1);
	for(re int i=1;i<=m;++i)c[i]=lower_bound(A+1,A+m+1,c[i])-A,d[i]=lower_bound(B+1,B+m+1,d[i])-B;
	for(re int i=1;i<=m;++i)v[c[i]].push_back((node){a[i],b[i],i});
	for(re int i=1;i<=m;++i){
		++tot;
		if(lst[a[i]])add(i,lst[a[i]]),add(tot,lst[a[i]]);
		add(tot,i+m),lst[a[i]]=tot;
		++tot;
		if(lst[b[i]])add(i,lst[b[i]]),add(tot,lst[b[i]]);
		add(tot,i+m),lst[b[i]]=tot;
	}
	memset(lst,0,sizeof(lst));
	for(re int i=m;i;--i){
		++tot;
		if(lst[a[i]])add(i,lst[a[i]]),add(tot,lst[a[i]]);
		add(tot,i+m),lst[a[i]]=tot;
		++tot;
		if(lst[b[i]])add(i,lst[b[i]]),add(tot,lst[b[i]]);
		add(tot,i+m),lst[b[i]]=tot;
	}
	memset(lst,0,sizeof(lst));
	for(re int j=1;j<=m;++j){
		for(re int k=0;k<v[j].size();++k){
			re int i=v[j][k].id;
			++tot;
			if(lst[a[i]])add(i+m,lst[a[i]]),add(tot,lst[a[i]]);
			add(tot,i),lst[a[i]]=tot;
			++tot;
			if(lst[b[i]])add(i+m,lst[b[i]]),add(tot,lst[b[i]]);
			add(tot,i),lst[b[i]]=tot;
		}
		for(re int k=0;k<v[j].size();++k){
			re int i=v[j][k].id;
			lst[a[i]]=lst[b[i]]=0;
		}
		for(re int k=v[j].size()-1;~k;--k){
			re int i=v[j][k].id;
			++tot;
			if(lst[a[i]])add(i+m,lst[a[i]]),add(tot,lst[a[i]]);
			add(tot,i),lst[a[i]]=tot;
			++tot;
			if(lst[b[i]])add(i+m,lst[b[i]]),add(tot,lst[b[i]]);
			add(tot,i),lst[b[i]]=tot;
		}
		for(re int k=0;k<v[j].size();++k){
			re int i=v[j][k].id;
			lst[a[i]]=lst[b[i]]=0;
		}
	}
	cnt1=cnt;
	for(re int i=1;i<=tot;++i)head1[i]=head[i];
	if(!check(m))return puts("No"),0;
	re int l=0,r=m-1,ans=m;
	while(l<=r){
		re int mid=l+r>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	puts("Yes");
	check(ans);
	printnum(B[ans],' ');
	re int num=0;
	for(re int i=1;i<=m;++i)if(bl[i]<bl[i+m])++num;
	printnum(num,'\n');
	for(re int i=1;i<=m;++i)if(bl[i]<bl[i+m])printnum(i,' ');
	pc('o',1);
}