#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll inf=1000000000000000000ll;
int n;
#define Maxn 500010
#define cout cerr
#define FR first
#define SE second

struct Gao{
	int a[Maxn];ll s[Maxn];
	ll to[Maxn][19][2];
	map<ll,int> mp;int cnt=0;
	vector<int> vec[Maxn][2];
	void pre(){
		for(int i=1;i<=cnt;++i)vec[i][0].clear(),vec[i][1].clear();cnt=0;mp.clear();
	}
	void init(int type){
		for(int i=2;i<=n;++i)s[i]=s[i-2]+a[i]-a[i-1];
		for(int i=0;i<=n;++i){
			int c=(i&1);
			to[i][0][c]=inf;
			to[i][0][c^1]=s[i+1];
		}
		for(register int i=n;i>=0;--i)
			for(register int j=1;j<=18&&i+(1<<j)<=n;++j){
			to[i][j][0]=min(to[i][j-1][0],to[i+(1<<(j-1))][j-1][0]),
			to[i][j][1]=min(to[i][j-1][1],to[i+(1<<(j-1))][j-1][1]);
		}
		if(type)return;
		for(int i=1;i<=n;++i)
			if(a[i]%2==0){
				ll tmp=s[i]-a[i]/2;
				int at=mp[tmp];
				if(!mp[tmp])at=mp[tmp]=++cnt;
				vec[at][i&1].push_back(i);
			}
	}
	pii calc(int pos,int type){//2|a[pos]
		int t=a[pos]/2;
		if(pos+1>n||a[pos+1]<=t)return pii(pos,n+1);
		pii res;res.FR=pos;int c=(pos&1);
		ll h1=s[pos]-t,h2=s[pos+1]-(a[pos+1]-t);
		for(int i=18;i>=0;--i)
			if(res.FR+(1<<i)<=n&&to[res.FR][i][c]>h1&&to[res.FR][i][c^1]>h2)res.FR+=(1<<i);
		if(type)return pii(res.FR,n+1);
		int at=mp[h1];
		int hh=upper_bound(vec[at][c].begin(),vec[at][c].end(),pos)-vec[at][c].begin();
		int t1=n+1;res.SE=n+1;
		if(hh<vec[at][c].size()&&vec[at][c][hh]<=res.FR)res.SE=min(res.SE,vec[at][c][hh]);
		at=mp[h2];
		hh=upper_bound(vec[at][c^1].begin(),vec[at][c^1].end(),pos)-vec[at][c^1].begin();
		if(hh<vec[at][c^1].size()&&vec[at][c^1][hh]<=res.FR)res.SE=min(res.SE,vec[at][c^1][hh]);
		return res;
	}
	int find(int pos){
		ll L=0,R=a[pos];
		pos--;int c=(pos&1);int tmp=pos;
		for(int i=18;i>=0;--i)
		if(tmp+(1<<i)<=n){
			ll toL=min(L,to[tmp][i][c]-s[pos]),toR=min(R,to[tmp][i][c^1]-s[pos+1]+a[pos+1]);
			if(toL+toR>=2){
				L=toL;R=toR;
				tmp+=(1<<i);
			}
		}
		return tmp;
	}
}gao;

multiset<int> S;
int A[Maxn],F[Maxn],a[Maxn];
int hhh[Maxn];
int lowbit(int x){return x&(-x);}
void upd(int x,int v){
	x=n+1-x;
	for(int i=x;i<=n+1;i+=lowbit(i))A[i]=max(A[i],v);
}
int query(int x){
	int res=-1000000000;
	x=n+1-x;
	for(int i=x;i;i-=lowbit(i))res=max(res,A[i]);
	return res;
}
void init(){
	for(int i=1;i<=n+1;++i)A[i]=-1000000000;
}
vector<int> del[Maxn];

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	int T;
	rd(T);
	while(T--){
	S.clear();
	rd(n);
	for(int i=1;i<=n+1;++i)del[i].clear();
	gao.pre();
	for(int i=1;i<=n;++i){
		rd(a[i]);gao.a[i]=a[i];
	}
	gao.init(1);
	
	for(int i=1;i<=n;++i)
		if(a[i]%2==0)hhh[i]=gao.calc(i,1).FR;
	gao.pre();
	for(int i=1;i<=n;++i)gao.a[i]=a[n-i+1];
	gao.init(0);
	init();
	upd(0,0);
	for(int i=1;i<=n;++i){
		for(int j=0;j<del[i].size();++j)S.erase(S.find(del[i][j]));
		if(a[i]%2==0){
			pii tmp=gao.calc(n-i+1,0);
			tmp.FR=n+1-tmp.FR;tmp.SE=n+1-tmp.SE;
			F[i]=query(tmp.FR-1)+1;
			if(tmp.SE>=tmp.FR)F[i]=max(F[i],F[tmp.SE]+1);
			del[hhh[i]+1].push_back(F[i]);
			S.insert(F[i]);	
		}
		int to=n-gao.find(n-i+1);
		int mx=query(to);
		if(S.size()){
			multiset<int>::iterator it;it=S.end();it--;
			mx=max(mx,*it);
		}
		mx--;
		upd(i,mx);
		if(i==n)printf("%d\n",n-mx);
	}
}
	return 0;
}/*
100
9
4 5 2 8 9 7 2 2 3
*/