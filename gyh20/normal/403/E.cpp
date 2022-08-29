#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<cstdio>
#include<vector>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
#define re register
int n,B,bl[200002],a[200002],b[200002],ans[200002];
struct node{int x,y;bool operator <(const node a)const{return y==a.y?x<a.x:y<a.y;};};
static char space[80000005],*sp=space;
template<typename T>
struct myalloc:allocator<T>{
    myalloc(){}
    template<typename T2>
    myalloc(const myalloc<T2> &a){}
    template<typename T2>
    myalloc<T>& operator=(const myalloc<T2> &a){return *this;}
    template<typename T2>
    struct rebind{typedef myalloc<T2> other;};
    inline T* allocate(size_t n){
        T *result=(T*)sp;sp+=n*sizeof(T);
        return result;
    }
    inline void deallocate(T* p,size_t n){}
};
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
vector<node,myalloc<node> >tmp,tmp1;
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
struct tree{
	int dfn[200002],siz[200002],head[200002],cnt,tim,dep[200002],pl[200002];
	struct edge{int to,next;}e[400002];
	vector<set<node> ,myalloc<set<node> > >v;
	set<node>b[502];
	set<node>::iterator it,it1;
	inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
	inline void dfs(re int x,re int y){
		dfn[x]=++tim,siz[x]=1,dep[x]=dep[y]+1,pl[tim]=x;
		for(re int i=head[x];i;i=e[i].next)
			if(e[i].to^y)
				dfs(e[i].to,x),siz[x]+=siz[e[i].to];
	}
	inline void ins(re int x,re int y){
		b[bl[dfn[x]]].insert((node){dfn[x],dfn[y]}),b[bl[dfn[y]]].insert((node){dfn[y],dfn[x]}),v[dfn[x]].insert((node){dfn[x],dfn[y]}),v[dfn[y]].insert((node){dfn[y],dfn[x]});
	}
	inline void del(re int x,re int y){
		b[bl[dfn[x]]].erase((node){dfn[x],dfn[y]}),b[bl[dfn[y]]].erase((node){dfn[y],dfn[x]}),v[dfn[x]].erase((node){dfn[x],dfn[y]}),v[dfn[y]].erase((node){dfn[y],dfn[x]});
	}
	inline void dsm(re int x,re int l,re int r){
		re int la=tmp.size();
		it=v[x].upper_bound((node){n+n,l});
		for(it1=v[x].begin();it1!=it;++it1)tmp.push_back((node){pl[(*it1).x],pl[(*it1).y]});
		it=v[x].lower_bound((node){0,r});
		for(it1=it;it1!=v[x].end();++it1)tmp.push_back((node){pl[(*it1).x],pl[(*it1).y]});
		for(re int i=la;i<tmp.size();++i)del(tmp[i].x,tmp[i].y);
	}
	inline void dbg(re int x,re int l,re int r){
		re int la=tmp.size();
		it=b[x].upper_bound((node){n+n,l});
		for(it1=b[x].begin();it1!=it;++it1)tmp.push_back((node){pl[(*it1).x],pl[(*it1).y]});
		it=b[x].lower_bound((node){0,r});
		for(it1=it;it1!=b[x].end();++it1)tmp.push_back((node){pl[(*it1).x],pl[(*it1).y]});
		for(re int i=la;i<tmp.size();++i)del(tmp[i].x,tmp[i].y);
	}
	inline void ask(re int x,re int y){
		if(siz[x]>siz[y])swap(x,y);
		re int l=dfn[x],r=dfn[x]+siz[x]-1;
		if(bl[l]==bl[r])for(re int i=l;i<=r;++i)dsm(i,l-1,r+1);
		else{
			for(re int i=l;i<=bl[l]*B;++i)dsm(i,l-1,r+1);
			for(re int i=bl[l]+1;i<=bl[r]-1;++i)dbg(i,l-1,r+1);
			for(re int i=(bl[r]-1)*B+1;i<=r;++i)dsm(i,l-1,r+1);
		}
	}
}T1,T2;
inline void print(re int* A){
	re int num=0;
	for(re int i=0;i<tmp.size();++i){
		re int x=tmp[i].x,y=tmp[i].y;
		if(A[x]==y)ans[++num]=x;
		else ans[++num]=y;
	}
	sort(ans+1,ans+num+1),num=unique(ans+1,ans+num+1)-ans-1;
	for(re int i=1;i<=num;++i)printnum(ans[i]-1,' ');
	pc('\n',0);
}
int main(){
	n=read(),B=sqrt(n);
	T1.v.resize(n+1),T2.v.resize(n+1);
	for(re int i=2;i<=n;++i)a[i]=read(),T1.add(a[i],i),T1.add(i,a[i]);
	for(re int i=2;i<=n;++i)b[i]=read(),T2.add(b[i],i),T2.add(i,b[i]);
	T1.dfs(1,1),T2.dfs(1,1);
	for(re int i=1;i<=n;++i)bl[i]=(i-1)/B+1;
	for(re int i=2;i<=n;++i)T1.ins(i,b[i]),T2.ins(i,a[i]);
	re int x=read()+1;
	pc('B',0),pc('l',0),pc('u',0),pc('e',0),pc('\n',0),printnum(x-1,'\n');
	T2.del(x,a[x]);
	tmp1.push_back((node){x,a[x]});
	while(1){
		tmp.clear();
		for(re int i=0;i<tmp1.size();++i)T1.ask(tmp1[i].x,tmp1[i].y);
		if(!tmp.size())break;
		pc('R',0),pc('e',0),pc('d',0),pc('\n',0),print(b);
		swap(tmp,tmp1),tmp.clear();
		for(re int i=0;i<tmp1.size();++i)T2.ask(tmp1[i].x,tmp1[i].y);
		if(!tmp.size())break;
		pc('B',0),pc('l',0),pc('u',0),pc('e',0),pc('\n',0),print(a);
		swap(tmp,tmp1);
	}
	return pc('o',1);
}