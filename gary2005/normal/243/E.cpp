/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=505;
typedef bitset<MAXN> BS;
int p[MAXN],to[MAXN];
char T[MAXN][MAXN];
char c[MAXN][MAXN];
bool e[MAXN][MAXN];
int fa[MAXN],ct[MAXN];
map<string ,int> app;
vector<BS> rnk;
vector<BS> cons;
int root(int x){
	return fa[x]=(fa[x]==x? x:root(fa[x]));
}
int n;
int is[MAXN];
bool ok[MAXN];
bool viss[MAXN];
vector<BS> pli[MAXN];
void solve2(vector<int> con){
//	cout<<"___!______\n";
	vector<int> od;
	queue<int> q;
	q.push(con[0]);
	od.PB(con[0]);
	viss[con[0]]=1;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		rb(i,0,n) if(e[now][i]&&!viss[i]){
			viss[i]=1;
			q.push(i);
			od.PB(i);
		}
	}
	assert(con.size()==od.size());
	con=od;
	BS unused;
	rb(i,1,n) unused.set(i);
	vector<BS> tmp;
	tmp.PB(cons[con[0]]);
	unused=unused^cons[con[0]];
//	auto it=cons[con[0]];
//	while(it.count()){
//		cout<<it._Find_first()<<' ';
//		it.reset(it._Find_first());
//	}
//	cout<<endl;
	rb(i,1,con.size()-1){
//		cout<<"...\n";
//		for(auto it:tmp){
//			while(it.count()){
//				cout<<it._Find_first()<<' ';
//				it.reset(it._Find_first());
//			}
//		}
//		cout<<endl;
		vector<int> ty(tmp.size(),-1);
		int cnt=0;
		rep(j,ty.size()){
			int tmpcnt=(tmp[j]&cons[con[i]]).count();
			if(tmpcnt){
				cnt++;
				if(tmpcnt==tmp[j].count()) ty[j]=1;
				else ty[j]=0;
			}
		}
//		if((unused&cons[con[i]]).count()) cnt++;
//		assert(cnt>=2);
		bool z=0;
		vector<BS> nx;
		BS tmptmp=unused&cons[con[i]];
		unused^=tmptmp;
		if(tmptmp.count()&&(ty[0]==1||(ty[0]==0&&cnt==1))){
			nx.PB(tmptmp);
			tmptmp.reset();
		}
		if(cnt==1&&ty[0]==0){
			z=1;
		}
		rep(j,ty.size()){
			auto it=ty[j];
			if(it==0){
				BS ZZ=cons[con[i]]&tmp[j];
				if(z==0){
					nx.PB(tmp[j]^ZZ);
					nx.PB(ZZ);
					z=1;
				}
				else{
					nx.PB(ZZ);
					nx.PB(tmp[j]^ZZ);
				}
			}
			else{
				if(it==1) z=1;
				nx.PB(tmp[j]);
			}
		}
		if(tmptmp.count()){
			nx.PB(tmptmp);
		}
		tmp=nx;
//		BS TTT=cons[con[i]];
//		while(TTT.count()){
//			cout<<TTT._Find_first()<<' ';
//			TTT.reset(TTT._Find_first());
//		}
//		cout<<endl;
//		for(auto it:tmp){
//			while(it.count()){
//				cout<<it._Find_first()<<' ';
//				it.reset(it._Find_first());
//			}
//		}
//		cout<<endl;
	}
	fill(is+1,is+1+n,-1);
	rb(i,0,n) pli[i].clear();
	rep(i,tmp.size()){
		BS tmptmp=tmp[i];
		while(tmptmp.count()){
			int j=tmptmp._Find_first();
			if(ok[j]) tmp[i].reset(j);
			ok[j]=1;
			is[j]=i;
			tmptmp.reset(j);
		}
	}
	vector<BS> nw;
	for(auto it:rnk){
		int j=it._Find_first();
		if(is[j]==-1) nw.PB(it);
		else{
			pli[is[j]].PB(it);
		}
	}
	rep(i,tmp.size()){
		if(tmp[i].count()) nw.PB(tmp[i]);
		for(auto it:pli[i]) nw.PB(it);
	}
	rnk=nw;
}
void solve(vector<int> con){
	int n=con.size();
	if(!n) return ;
	mp bst=II(-INF,-INF);
	rep(i,n) check_max(bst,II(int(cons[con[i]].count()),i));
	swap(con[0],con[bst.SEC]);
	rep(i,n) fa[i]=i;
	rep(i,n) rep(j,n) if(i!=j&&e[con[i]][con[j]]) fa[root(i)]=root(j);
	vector<int> now,nex;
	rep(i,n) if(root(i)!=root(0)) nex.PB(con[i]);else now.PB(con[i]);
	solve(nex);
	solve2(now);
//	cout<<")))"<<endl;
//	for(auto itt:now){
//		auto it=cons[itt];
//		while(it.count()){
//			cout<<it._Find_first()<<' ';
//			it.reset(it._Find_first());
//		}
//	}
//	cout<<endl;
//	for(auto it:rnk){
//		while(it.count()){
//			cout<<it._Find_first()<<' ';
//			it.reset(it._Find_first());
//		}
//		cout<<"|";
//	}
//	cout<<endl;
//	cout<<")))"<<endl;
}
int main(){
//	freopen("matrix.in","r",stdin);
	scanf("%d",&n);
	rb(i,1,n){
		string ss;
		cin>>ss;
		rep(j,n) c[i][j+1]=ss[j];
		BS s;
		rep(j,n) if(ss[j]=='1') s.set(j+1);
		if(s.count()&&!app[ss]){
			app[ss]=1;
			cons.PB(s);
		}
	}
	vector<int> con;
	rep(i,cons.size()) con.PB(i);
	for(auto i:con) for(auto j:con){
		int cc=(cons[i]&cons[j]).count();
		e[i][j]=cc!=0&&cc!=cons[i].count()&&cc!=cons[j].count();	
	}
	rep(i,cons.size()) ct[i]=cons[i].count();
	solve(con);
	int cnt=0;
	for(auto it:rnk){
		while(it.count()){
			int j=it._Find_first();
			p[j]=++cnt;
			it.reset(j);
		}
	}
	rb(i,1,n) if(p[i]==0) p[i]=++cnt;
	rb(i,1,n) to[p[i]]=i;
	rb(i,1,n) rb(j,1,n) T[i][j]=c[i][to[j]];
	rb(i,1,n){
		int have1=0;
		rb(j,1,n){
			if(T[i][j]=='1'){
				if(have1==2){
					cout<<"NO"<<endl;
					return 0;
				}
				have1=1;
			}
			else if(have1) {have1=2;}
		}
	}
	cout<<"YES"<<endl;
	rb(i,1,n){
		rb(j,1,n) cout<<T[i][j];
		cout<<endl;
	}
	return 0;
}