#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pr;
struct P{
	vector<pr> v;
	void push(int x,int y){v.emplace_back(x,y);}
	void clear(){v.clear();}
	bool count(int x){for(pr i:v)if(i.first==x)return 1;return 0;}
	int len;
}t[600005];
int n,m,tag[600005],k;
P operator +(P a,P b){
	a.len+=b.len;
	for(pr i:b.v){
		bool flag=0;
		for(pr &j:a.v)if(j.first==i.first)j.second+=i.second,flag=1;
		if(flag)continue;
		a.v.push_back(i);
		if(a.v.size()<=k)continue;
		int mn=1e9;
		for(pr j:a.v)mn=min(mn,j.second);
		vector<pr> c;
		for(pr j:a.v)if(j.second>mn)c.emplace_back(j.first,j.second-mn);
		a.v=c;
	}
	return a;
}
void Build(int p,int l,int r){
	if(l==r){
		int x;
		scanf("%d",&x),t[p].push(x,1),t[p].len=1;
		return ;
	}
	int mid=(l+r)/2;
	Build(p*2,l,mid),Build(p*2+1,mid+1,r);
	t[p]=t[p*2]+t[p*2+1];
}
void Tag(int p,int x){
	t[p].clear(),t[p].push(x,t[p].len),tag[p]=x;
}
void Pushdown(int p){
	if(tag[p])Tag(p*2,tag[p]),Tag(p*2+1,tag[p]),tag[p]=0;
}
void Make(int p,int l,int r,int x,int y,int z){
	if(x<=l&&r<=y)return Tag(p,z),void();
	Pushdown(p);
	int mid=(l+r)/2;
	if(x<=mid)Make(p*2,l,mid,x,y,z);
	if(mid<y)Make(p*2+1,mid+1,r,x,y,z);
	t[p]=t[p*2]+t[p*2+1];
}
P Query(int p,int l,int r,int x,int y){
	if(x<=l&&r<=y)return t[p];
	Pushdown(p);
	int mid=(l+r)/2;
	if(x>mid)return Query(p*2+1,mid+1,r,x,y);
	if(y<=mid)return Query(p*2,l,mid,x,y);
	return Query(p*2,l,mid,x,y)+Query(p*2+1,mid+1,r,x,y);
}
int main() {
	cin>>n>>m>>k,k=100/k,Build(1,1,n);
	for(int i=1,x,y,z,o;i<=m;i++){
		scanf("%d%d%d",&o,&x,&y);
		if(o==2){
			vector<pr> res=Query(1,1,n,x,y).v;
			cout<<res.size()<<' ';
			for(pr i:res)cout<<i.first<<' ';
			cout<<'\n';
		}
		else scanf("%d",&z),Make(1,1,n,x,y,z);
	}
}