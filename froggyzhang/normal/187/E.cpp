#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
const int inf=1e9;
const ll infll=1e18;
int n,S,lim,a[N];
class Segment_Tree{
	struct node{
		int siz;
		ll sum;
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
public:
	inline void update(int u){
		t[u].siz=t[ls].siz+t[rs].siz;
		t[u].sum=t[ls].sum+t[rs].sum;
	}
	void build(int u,int L,int R){
		t[u].siz=0;
		t[u].sum=0;
		if(L==R){
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
	}
	void Change(int u,int L,int R,int p,int d){
		if(L==R){
			++t[u].siz;
			t[u].sum+=d;
			return;
		}
		int mid=(L+R)>>1;
		p<=mid?Change(ls,L,mid,p,d):Change(rs,mid+1,R,p,d);
		update(u);
	}
	ll Find(int u,int L,int R,int cnt){
		if(L==R){
			return !t[u].siz?0:1LL*cnt*(t[u].sum/t[u].siz);	
		}
		int mid=(L+R)>>1;
		if(cnt<=t[rs].siz)return Find(rs,mid+1,R,cnt);
		return t[rs].sum+Find(ls,L,mid,cnt-t[rs].siz);
	}
}T;
pair<ll,vector<int> > Solve(int op){
	vector<int> P;
	if(S==n||!lim)return make_pair(infll,P);
	if(lim>=n-1-(S-1)){
		if(S>1&&lim==n-1)return make_pair(infll,P);
		ll tmp=a[S]-a[1];
		tmp+=a[n]-a[1];
		for(int i=n-1-lim;i>=1;--i){
			P.push_back(i);
		}
		for(int i=n-lim;i<=n;++i){
			if(i^S)P.push_back(i);	
		}
		if(op){
			for(auto &x:P){
				x=n+1-x;
			}
		}
		return make_pair(tmp,P);
	}
	static int c[N],tot,b[N],len;
	static ll suf[N];
	ll all=a[n]-a[1];
	tot=len=0;
	for(int i=S+2;i<=n;++i){
		c[++tot]=a[i]-a[i-1];
	}
	suf[tot+1]=0;
	for(int i=tot;i>=1;--i){
		suf[i]=suf[i+1]+c[i];	
	}
	for(int i=1;i<=tot;++i){
		b[++len]=c[i];
	}
	sort(b+1,b+len+1);
	len=unique(b+1,b+len+1)-b-1;
	for(int i=1;i<=tot;++i){
		c[i]=lower_bound(b+1,b+len+1,c[i])-b;
	}
	T.build(1,1,len);
	for(int i=1;i<lim-1;++i){
		T.Change(1,1,len,c[i],b[c[i]]);
	}
	ll mn=infll;
	int pos=-1;
	for(int i=lim-1;i<=tot;++i){
		T.Change(1,1,len,c[i],b[c[i]]);
		ll w=3*all-suf[i+1]-2*T.Find(1,1,len,lim-1);
		if(w<mn){
			mn=w;
			pos=i;
		}
	}
	static int p[N],tag[N];
	for(int i=1;i<=n;++i)tag[i]=0;
	for(int i=1;i<=pos;++i){
		p[i]=i;
	}
	sort(p+1,p+pos+1,[&](int i,int j){return c[i]>c[j];});
	for(int i=1;i<lim;++i){
		tag[S+p[i]]=1;
	}
	for(int i=S-1;i>=1;--i){
		if(S^1)P.push_back(i);
	}
	tag[n]=1;
	for(int i=S+1,las=S;i<=n;++i){
		if(tag[i]){
			for(int j=i;j>las;--j){
				P.push_back(j);
			}
			las=i;
		}
	}
	if(op){
		for(auto &x:P){
			x=n+1-x;
		}
	}
	return make_pair(mn+a[S]-a[1]-2*(a[S+1]-a[1]),P);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>lim>>S;
	lim=n-1-lim;
	for(int i=1;i<=n;++i){
		cin>>a[i];	
	}
	pair<ll,vector<int> > ans=Solve(0);
	lim=n-1-lim;
	S=n+1-S;
	for(int i=1;i<=n;++i){
		a[i]=inf-a[i];	
	}
	reverse(a+1,a+n+1);
	ans=min(ans,Solve(1));
	if(ans.first==infll){
		cout<<-1<<'\n';
		return 0;	
	}
	cout<<ans.first<<'\n';
	for(auto x:ans.second){
		cout<<x<<' ';
	}
	return 0;
}