#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int inf=0x7fffffff;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,K;
vector<pair<int,int> > a[4];
vector<int> s[4];
int b[N],len;
vector<int> book;
struct SGT{
	const double alpha=0.78;
	int cnt,rt;
	SGT(){cnt=0;}
	struct node{
		int ch[2],siz,sum,val;
		int id;
	}t[N];
	#define ls t[u].ch[0]
	#define rs t[u].ch[1]
	inline int NewNode(pair<int,int> data){
		int u=++cnt;
		t[u].siz=1;
		t[u].id=data.second;
		t[u].sum=t[u].val=data.first;
		return u;
	}
	inline void update(int u){
		t[u].siz=t[ls].siz+t[rs].siz+1;
		t[u].sum=t[ls].sum+t[rs].sum+t[u].val;
	}
	inline bool isbad(int u){
		return t[u].siz*alpha<=max(t[ls].siz,t[rs].siz);
	}
	void dfs(int u){
		if(!u)return;
		dfs(ls);
		b[++len]=u;
		dfs(rs);	
	}
	void build(int l,int r,int &u){
		if(l>r)return (void)(u=0);
		int mid=(l+r)>>1;
		u=b[mid];
		build(l,mid-1,ls);
		build(mid+1,r,rs);
		update(u);	
	}
	void rebuild(int &u){
		len=0;
		dfs(u);
		build(1,len,u);	
	}
	int Ask(int u,int nd){
		if(!u||!nd)return 0;
		if(t[ls].siz+1<=nd)return t[ls].sum+t[u].val+Ask(rs,nd-1-t[ls].siz);
		return Ask(ls,nd);
	}
	void Insert(int &u,pair<int,int> val){
		if(!u)return (void)(u=NewNode(val));
		val.first<=t[u].val?Insert(ls,val):Insert(rs,val);
		if(isbad(u))rebuild(u);
		update(u);
	}
}T;
int main(){
	n=read(),m=read(),K=read();
	for(int i=1;i<=n;++i){
		int t=read(),x=read(),y=read();
		a[x<<1|y].emplace_back(t,i);
	}
	for(int i=0;i<4;++i){
		sort(a[i].begin(),a[i].end());
		s[i].resize(a[i].size());
		if(!a[i].empty()){
			s[i][0]=a[i][0].first;
			for(int j=1;j<(int)a[i].size();++j){
				s[i][j]=a[i][j].first+s[i][j-1];
			}
		}
	}
	for(auto x:a[0]){
		T.Insert(T.rt,x);
	}
	for(int i=K+1;i<(int)a[1].size();++i){
		T.Insert(T.rt,a[1][i]);
	}
	for(int i=K+1;i<(int)a[2].size();++i){
		T.Insert(T.rt,a[2][i]);
	}
	int ans=inf,pos=-1;
	for(int i=0;i<=min(m,(int)a[3].size());++i){
		if(i<=K&&K-i<(int)a[1].size()){
			T.Insert(T.rt,a[1][K-i]);
		}
		if(i<=K&&K-i<(int)a[2].size()){
			T.Insert(T.rt,a[2][K-i]);	
		}
		int w=0;
		if(i<K){
			if(m-2*K+i<0)continue;
			if((int)a[1].size()<K-i)continue;
			if((int)a[2].size()<K-i)continue;
			if(T.t[T.rt].siz<m-2*K+i)continue;
			w=s[1][K-i-1]+s[2][K-i-1]+(!i?0:s[3][i-1])+T.Ask(T.rt,m-2*K+i);
		}
		else{
			if(T.t[T.rt].siz<m-i)continue;
			w=(!i?0:s[3][i-1])+T.Ask(T.rt,m-i);
		}
		if(w<ans){
			ans=w;
			pos=i;
		}
	}
	if(ans==inf){
		return !printf("-1\n");
	}
	for(int i=0;i<pos;++i){
		book.push_back(a[3][i].second);
	}
	static vector<pair<int,int> > tmp;
	tmp=a[0];
	int sz=0;
	if(pos<K){
		for(int i=0;i<=K-pos-1;++i){
			book.push_back(a[1][i].second);
			book.push_back(a[2][i].second);
		}
		for(int i=K-pos;i<(int)a[1].size();++i)tmp.push_back(a[1][i]);
		for(int i=K-pos;i<(int)a[2].size();++i)tmp.push_back(a[2][i]);
		sz=m-2*K+pos;
	}
	else{
		tmp.insert(tmp.end(),a[1].begin(),a[1].end());
		tmp.insert(tmp.end(),a[2].begin(),a[2].end());
		sz=m-pos;
	}
	sort(tmp.begin(),tmp.end());
	for(int i=0;i<sz;++i){
		book.push_back(tmp[i].second);
	}
	printf("%d\n",ans);
	for(auto x:book){
		printf("%d ",x);
	}
	printf("\n");
	return 0;
}