#include<bits/stdc++.h>
using namespace std;
#define N 2005
typedef long long ll;
#define y1 ysgh
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
int n,m,Q,cnt[N];
struct cmp{
	bool operator () (int i,int j)const{
		return cnt[i]==cnt[j]?i<j:cnt[i]<cnt[j];	
	}	
};
set<int,cmp> s;
bitset<N> B[N],tmp;
struct Data{
	int x1,y1,x2,y2;
	Data(int _x1,int _y1,int _x2,int _y2){x1=_x1,x2=_x2,y1=_y1,y2=_y2;}
};
struct cmp_Data{
	bool operator () (Data a,Data b)const{
		return a.x1==b.x1?a.x2<b.x2:a.x1<b.x1;		
	}	
};
set<Data,cmp_Data> ans;
vector<Data> c[N];
Data check(int x,int y){
	if(x>y)swap(x,y);
	auto t=B[x]&B[y];
	auto X=B[x]^t;
	auto Y=B[y]^t;
	if(!X.count()||!Y.count())return Data(-1,-1,-1,-1);
	int px=X._Find_first();
	int py=Y._Find_first();
	if(px>py)swap(px,py);
	return Data(x,px,y,py);
}
void Insert(int u,int opt){
	auto it=s.lower_bound(u);
	if(opt){
		if(it!=s.end()){
			Data t=check(u,*it);
			if(~t.x1&&!ans.count(t))ans.insert(t),c[u].emplace_back(t),c[*it].emplace_back(t);	
		}
	}
	else{
		if(it!=s.begin()){
			--it;
			Data t=check(u,*it);
			if(~t.x1&&!ans.count(t))ans.insert(t),c[u].emplace_back(t),c[*it].emplace_back(t);
		}
	}	
}
void Del(int u){
	s.erase(u);
	for(auto x:c[u]){
		if(ans.count(x))ans.erase(x);
	}
	c[u].clear();
	auto it=s.lower_bound(u);
	if(it!=s.end()){
		Insert(*it,0);	
	}
	it=s.lower_bound(u);
	if(it!=s.begin()){
		--it;
		Insert(*it,1);
	}
}
int main(){
	n=read(),m=read(),Q=read();
	for(int i=1;i<=n;++i){
		s.insert(i);	
	}
	while(Q--){
		int u=read(),l=read(),r=read();
		if(l>r)swap(l,r);
		Del(u);
		tmp.set();
		tmp>>=l,tmp<<=N-(r-l+1),tmp>>=N-r-1;
		B[u]^=tmp;
		cnt[u]=B[u].count();
		Insert(u,0),Insert(u,1);
		s.insert(u);
		if(ans.empty())printf("-1\n");
		else{
			auto t=*ans.begin();
			printf("%d %d %d %d\n",t.x1,t.y1,t.x2,t.y2);
		}
	}
	return 0;
}