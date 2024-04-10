#include<bits/stdc++.h>
const int maxn=5000003,maxm=11100000,inf=0x3f3f3f3f;
struct IO{
	IO(){};char c;
	inline char gc(){
		static char buf[maxn],*p1=buf,*p2=buf;
		return p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++;
	}
	inline IO&operator>>(int &_){
		_=0;c=gc();while(c<'0'||c>'9'){c=gc();}
		while(c>='0'&&c<='9'){_=_*10+(c^48);c=gc();}return *this;
	}
}io;
 
template<typename T>
inline void swap(T &a,T &b){
	T temp=a;a=b;b=temp;
}
 
template<typename T>
struct heap{
	T a[maxn];int len;T val[maxn];int pos[maxn];
	heap(){len=0;}
	void shift_up(int id){
		while(id!=1){
			int temp=id>>1;
			if(val[a[temp]]>val[a[id]]){
				swap(a[temp],a[id]);
				swap(pos[a[temp]],pos[a[id]]);
				id=temp;
			}
			else break;
		}
	}
	void shift_down(int id){
		while((id<<1)<=len){
			int temp=id<<1;
			if(temp+1<=len&&val[a[temp]]>val[a[temp+1]]) temp++;
			if(val[a[temp]]<val[a[id]]){
				swap(a[temp],a[id]);
				swap(pos[a[temp]],pos[a[id]]);
				id=temp;
			}
			else break;
		}
	}
	void insert(const int &key,const int &value){
		a[++len]=key;pos[key]=len,val[key]=value;
		shift_up(len);
	}
	void pop(){
		swap(a[1],a[len]);swap(pos[a[1]],pos[a[len--]]);
		shift_down(1);
	}
	void modify(const int &key,const int &value){
		val[key]=value;
		shift_up(pos[key]);shift_down(pos[key]);
	}
	T top(){return a[1];}
};heap<int> hp;
 
int n,m,s,edge_cnt,fir[maxn];int dis[maxn];
 
struct edge{
	int v,nxt,w;
}e[maxm<<1];
 
inline void add_edge(int u,int v,int w){
	e[++edge_cnt].nxt=fir[u];e[edge_cnt].v=v,e[edge_cnt].w=w;fir[u]=edge_cnt;
}
 
void dijkstra(){
	for(int i=1;i<=n;i++) dis[i]=inf;
	dis[s]=0;hp.insert(s,dis[s]);
	// for(int i=1;i<=n;i++) hp.insert(i,dis[i]);
	while(hp.len){
		int now=hp.top();hp.pop();
		for(int i=fir[now];i;i=e[i].nxt){
			int v=e[i].v;
			if(dis[v]>dis[now]+e[i].w){
				dis[v]=dis[now]+e[i].w;
				if(hp.pos[v]) hp.modify(v,dis[v]);
				else hp.insert(v,dis[v]);
			}
		}
	}
}
#define mp make_pair
using namespace std;
vector<pair<int,int> > vec[100003];
bool fafa[53];
int id[53],num[53];
int hhz[53];
signed main(){
	io>>n>>m;s=1;
	for(int i=1;i<=m;i++){
		int u,v,w;
		io>>u>>v>>w;
		vec[u].push_back(mp(v,w)),vec[v].push_back(mp(u,w));
		//add_edge(u,v,w);
	}
	int cnt=n;
	for(int i=1; i<=n; i++)
	{
		memset(fafa,0,sizeof(fafa));
		for(auto x:vec[i]) fafa[x.second]=1;
		int C=0;
		for(int i=1; i<=50; ++i) if(fafa[i]) num[++C]=i,hhz[i]=C;
		for(auto x:vec[i])
		{
		add_edge(x.first,cnt+hhz[x.second],0);
		for(int i=1; i<=C; ++i)
		add_edge(cnt+i,x.first,(num[i]+x.second)*(num[i]+x.second));	
		}
		
		cnt=cnt+C;
	}
    int N=n;
	n=cnt;
	dijkstra();
	for(int i=1;i<=N;i++) if(dis[i]==inf) printf("-1 ");
	else printf("%lld ",dis[i]);
	return 0;
}