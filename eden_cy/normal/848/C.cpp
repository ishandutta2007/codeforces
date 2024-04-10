#include<set>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 100005

typedef long long ll;

inline void rd(int &x) {
	static char c;x=0;
	while(c=getchar(),c<48);
	do x=(x<<3)+(x<<1)+(c^48);
	while(c=getchar(),c>47);
}

int n,m;

ll sum[M];
void Add(int x,int a) {
	for(;x<=n;x+=x&-x) sum[x]+=a;
}
void Update(int l,int r,int a) {
	Add(l,a);Add(r+1,-a);
}
ll Query(int x) {
	ll tmp=0;
	for(;x;x^=x&-x) tmp+=sum[x];
	return tmp+sum[0];
}
struct node{
	int x,y,f;
}Q[M];
struct section{
	int x_l,x_r,y_l,y_r,v;
};
struct temp{
	int x,l,r,v,f;
	bool operator <(const temp &s) const{
		if(x==s.x) return f<s.f;
		else return x<s.x;
	}
}Tmp[M<<2];
vector<section> sec[M];
int lst[M];
ll Ans[M];
set<int> S[M];
set<int> :: iterator it,pre,nxt;
vector<node> G[M];
char op[10];
int val[M];

void Init() {
	FOR(i,1,m) if(Q[i].f==2) G[Q[i].y].push_back((node){Q[i].x,i});
	FOR(i,1,n) {
		if(lst[val[i]]) Update(1,lst[val[i]],i-lst[val[i]]);
		lst[val[i]]=i;
		FOR(j,0,G[i].size()-1) {
			node t=G[i][j];
			Ans[t.y]=Query(t.x);
		}
	}
	FOR(i,1,n) S[val[i]].insert(i);
	FOR(i,1,m) if(Q[i].f==1) {
		int x=Q[i].x,v=Q[i].y;
		nxt=pre=it=S[val[x]].find(x);
		if(it!=S[val[x]].begin()) {
			pre--;nxt++;
			int pos=n;
			if(nxt!=S[val[x]].end()) pos=(*nxt)-1;
			sec[i].push_back((section){1,*pre,*it,pos,(*pre)-(*it)});
		}
		nxt=pre=it;
		nxt++;
		if(nxt!=S[val[x]].end()) {
			int pos=1;
			if(it!=S[val[x]].begin()) {
				pre--;pos=(*pre)+1;
			}
			sec[i].push_back((section){pos,*it,*nxt,n,(*it)-(*nxt)});
		}
		
		S[val[x]].erase(it);
		val[x]=v;
		S[val[x]].insert(x);
		
		nxt=pre=it=S[val[x]].find(x);
		if(it!=S[val[x]].begin()) {
			pre--;nxt++;
			int pos=n;
			if(nxt!=S[val[x]].end()) pos=(*nxt)-1;
			sec[i].push_back((section){1,*pre,*it,pos,(*it)-(*pre)});
		}
		nxt=pre=it;
		nxt++;
		if(nxt!=S[val[x]].end()) {
			int pos=1;
			if(it!=S[val[x]].begin()) {
				pre--;pos=(*pre)+1;
			}
			sec[i].push_back((section){pos,*it,*nxt,n,(*nxt)-(*it)});
		}
	}
}
void CDQ(int l,int r) {
	if(l==r) return ;
	int mid=l+r>>1;
	int top=0;
	FOR(i,l,mid) if(Q[i].f==1) {
		FOR(j,0,sec[i].size()-1) {
			Tmp[++top]=(temp){sec[i][j].x_l,sec[i][j].y_l,sec[i][j].y_r,sec[i][j].v,1};
			Tmp[++top]=(temp){sec[i][j].x_r+1,sec[i][j].y_l,sec[i][j].y_r,-sec[i][j].v,1};
		}
	}
	FOR(i,mid+1,r) if(Q[i].f==2) Tmp[++top]=(temp){Q[i].x,Q[i].y,Q[i].y,i,2};
	sort(Tmp+1,Tmp+top+1);
	FOR(i,1,top) {
		if(Tmp[i].f==1) Update(Tmp[i].l,Tmp[i].r,Tmp[i].v);
		else Ans[Tmp[i].v]+=Query(Tmp[i].l);
	}
	CDQ(l,mid);
	CDQ(mid+1,r);
}
int main() {
	rd(n);rd(m);
	FOR(i,1,n) rd(val[i]);
	FOR(i,1,m) rd(Q[i].f),rd(Q[i].x),rd(Q[i].y);
	Init();
	memset(sum,0,sizeof(sum));
	CDQ(1,m);
	FOR(i,1,m) if(Q[i].f==2) {
		if(Q[i].x==Q[i].y) Ans[i]=0;
		printf("%lld\n",Ans[i]);
	}
	return 0;
}