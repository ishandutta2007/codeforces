#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define tm arin
const ll mod=1e9+7;
const int N=2e5+555;
int n,m,q,z;
pair<ll,int>a[N];
int qt[N];
ll ql[N],qr[N];
ll ans[N];
vector<pair<int,int> >ed[N];
ll bl[N],br[N],tm[N];
int f[N*20];
const int iu=18;
int lg[N*2];
ll st[N][iu],nid[N][iu];
ll sh[N][iu];
void adde(int u,int v,int t){
	ed[t].push_back({u,v});
}
void add(int id,int l,int r){
	//cout << id << ' ' << l << ' ' << r << endl;
	int duh=lg[r-l+1];
	int e=r-(1<<duh)+1;
	st[l][duh]=max(st[l][duh],min(tm[id],sh[l][duh]));
	st[e][duh]=max(st[e][duh],min(tm[id],sh[e][duh]));
	adde(id,nid[l][duh],min(tm[id],sh[l][duh]));
	adde(id,nid[e][duh],min(tm[id],sh[e][duh]));
}
int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
void join(int x,int y){
	x=find(x);y=find(y);
	f[x]=y;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> q;
	for(int i=2; i<262144 ;i++) lg[i]=lg[i/2]+1;
	a[++m]={-1,-q-1};
	a[++m]={1LL<<n,q+1};
	for(int i=1; i<=q ;i++){
		string s;
		cin >> s >> ql[i] >> qr[i];
		if(s[0]=='b') qt[i]=1;
		else qt[i]=2;
		if(qt[i]==1){
			a[++m]={ql[i],-i};
			a[++m]={qr[i],i};
		}
	}
	sort(a+1,a+m+1);
	for(int i=1; i<m ;i++){
		ll cl=a[i].fi+(i%2);
		ll cr=a[i+1].fi-(i%2);
		int cc;
		if(i%2==1) cc=q+1;
		else cc=-a[i].se;
		if(cl>cr) continue;
		if(cl==cr){
			bl[++z]=cl;br[z]=cr;tm[z]=cc;
		}
		else{
			ll fk=cl^cr;
			while(fk!=(fk&-fk)) fk^=fk&-fk;
			ll mid=cl|(fk-1);
			bl[++z]=cl;br[z]=mid;tm[z]=cc;
			bl[++z]=mid+1;br[z]=cr;tm[z]=cc;
		}
	}
	
	int ptr=z;
	for(int j=0; j<iu ;j++){
		for(int i=1; i<=z ;i++){
			nid[i][j]=++ptr;
			if(j==0) sh[i][j]=tm[i];
			else if(i+(1<<(j-1))<=z){
				sh[i][j]=max(sh[i][j-1],sh[i+(1<<(j-1))][j-1]);
			}
		}
	}
	for(int i=1; i<=z ;i++){
		//cout << "block " << i << ' ' << bl[i] << ' ' << br[i] << ' ' << tm[i] << endl;
		for(int k=n-1; k>=0 ;k--){//join edges about moving from block i through xor 2^k
			ll cl,cr;
			bool die=false;
			if(br[i]-bl[i]+1>(1LL<<k)){
				cr=bl[i]|((1LL<<(k+1))-1);
				cl=cr^((1LL<<(k+1))-1);
				die=true;
			}
			else{
				cl=bl[i]^(1LL<<k);
				cr=br[i]^(1LL<<k);
			}
			int zl=lower_bound(br+1,br+z+1,cl)-br;
			int zr=lower_bound(bl+1,bl+z+1,cr+1)-bl-1;
			//cout << cl << ' ' << cr << endl;
			add(i,zl,zr);
			if(die) break;
		}
		adde(i,nid[i][0],tm[i]);
	}
	for(int j=iu-2; j>=0 ;j--){
		for(int i=1; i<=z ;i++){
			st[i][j]=max(st[i][j],st[i][j+1]);
			adde(nid[i][j],nid[i][j+1],min(st[i][j+1],sh[i][j]));
			if(i>(1<<j)){
				st[i][j]=max(st[i][j],st[i-(1<<j)][j+1]);
				adde(nid[i][j],nid[i-(1<<j)][j+1],min(st[i-(1<<j)][j+1],sh[i][j]));
			}
		}
	}
	for(int i=1; i<=ptr ;i++) f[i]=i;
	for(int i=q+1; i>=1 ;i--){
		for(auto c:ed[i]) join(c.fi,c.se);
		if(qt[i]==2){
			int cl=lower_bound(br+1,br+z+1,ql[i])-br;
			int cr=lower_bound(br+1,br+z+1,qr[i])-br;
			ans[i]=find(cl)==find(cr);
		}
	}
	for(int i=1; i<=q ;i++){
		if(qt[i]==2) cout << ans[i] << '\n';
	}
}