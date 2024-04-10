#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
typedef pair<int,int> pii;
int n,Q,a[N],tot,ans[N],B,ch;
pii c[N];
struct Data{
	int l,r,t,id;	
	friend bool operator < (const Data &a,const Data &b){
		return a.l/B==b.l/B?(a.r/B==b.r/B?a.t<b.t:a.r<b.r):a.l<b.l;	
	}
}q[N];
int jb;
unordered_map<int,int> mp;
int tmp[N],cnt[N];
void Change(int x,int w){
	--tmp[cnt[x]];
	cnt[x]+=w;
	++tmp[cnt[x]];
}
int Query(){
	for(int i=1;;++i){
		if(!tmp[i])return i;
	}	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(!mp.count(a[i]))mp[a[i]]=++jb;
		a[i]=mp[a[i]];
	}
	for(int i=1;i<=Q;++i){
		int opt;
		cin>>opt;
		if(opt==1){
			int l,r;
			cin>>l>>r;
			++tot;
			q[tot]={l,r,ch,tot};	
		}
		else{
			++ch;
			cin>>c[ch].first>>c[ch].second;	
			if(!mp.count(c[ch].second))mp[c[ch].second]=++jb;
			c[ch].second=mp[c[ch].second];
		}
	}
	B=min(tot,1600);
	sort(q+1,q+tot+1);
	int l=1,r=0,t=0;
	for(int i=1;i<=tot;++i){
		int ql=q[i].l,qr=q[i].r;
		while(r<qr)Change(a[++r],1);
		while(l>ql)Change(a[--l],1);
		while(r>qr)Change(a[r--],-1);
		while(l<ql)Change(a[l++],-1);
		auto Gao=[&](int p,int &w)->void{
			if(p>=l&&p<=r)Change(a[p],-1);
			swap(a[p],w);
			if(p>=l&&p<=r)Change(a[p],1);
		};
		while(t<q[i].t){
			++t;
			Gao(c[t].first,c[t].second);	
		}
		while(t>q[i].t){
			Gao(c[t].first,c[t].second);
			--t;
		}
		ans[q[i].id]=Query();
	}
	for(int i=1;i<=tot;++i){
		cout<<ans[i]<<'\n';
	}
	return 0;
}