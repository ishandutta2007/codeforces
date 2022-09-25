#include<bits/stdc++.h>
using namespace std;
#define N 1000010
typedef long long ll;
int n,m,a[N],L[N],R[N];
ll ans[N];
struct Query{
	int l,r;	
}q[N];
vector<pair<int,int> > vec[N];
template<class T>
class BIT{
	T b[N];
	inline int lowbit(int x){return x&(-x);}
public:
	void Add(int x,int d){
		while(x<=n)b[x]+=d,x+=lowbit(x);	
	}
	T Ask(int x){
		T ans=0;
		while(x)ans+=b[x],x-=lowbit(x);
		return ans;
	}
};
BIT<int> Lt,Rt;
BIT<ll> Ls,Rs;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		R[i]=n,L[i]=1;
	}
	for(int i=1;i<=n;++i){
		static int st[N],top;
		while(top&&a[i]>a[st[top]])--top;
		if(top)L[i]=st[top]+1;
		st[++top]=i;
	}
	for(int i=n;i>=1;--i){
		static int st[N],top;
		while(top&&a[i]>a[st[top]])--top;
		if(top)R[i]=st[top]-1;
		st[++top]=i;
	}
	for(int i=1;i<=m;++i){
		cin>>q[i].l;
	}
	for(int i=1;i<=m;++i){
		cin>>q[i].r;
	}
	for(int i=1;i<=m;++i){
		vec[q[i].l-1].emplace_back(i,-1);
		vec[q[i].r].emplace_back(i,1);
		ans[i]=q[i].r-q[i].l+1;	
	}
	for(int i=1;i<=n;++i){
		Lt.Add(L[i],1),Rt.Add(R[i],1);
		Ls.Add(L[i],L[i]),Rs.Add(R[i],R[i]);
		for(auto [id,w]:vec[i]){
			ans[id]+=w*((Rs.Ask(q[id].r)+1LL*q[id].r*(Rt.Ask(n)-Rt.Ask(q[id].r)))-(1LL*q[id].l*Lt.Ask(q[id].l)+Ls.Ask(n)-Ls.Ask(q[id].l)));	
		}	
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}