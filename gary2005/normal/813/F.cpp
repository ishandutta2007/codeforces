/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
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
const int MAXN=1e5+20;
struct bipartite_checking_dsu{
	vector<mp> fatherundo;
	vector<mp> parityundo;
	vector<mp> rankundo;
	vector<bool> okundo;
	bool isok;
	int fa[MAXN],ran[MAXN];
	bool pa[MAXN];
	bipartite_checking_dsu(){
		rb(i,1,1e5) fa[i]=i,pa[i]=0,ran[i]=0;
		isok=true;
	}
	void undo(){
		if(okundo.back()){
			isok=true;
		}
		okundo.POB();
		mp tmp=fatherundo.back();
		fatherundo.POB();
		fa[tmp.FIR]=tmp.SEC;
		tmp=parityundo.back();
		parityundo.POB();
		pa[tmp.FIR]=tmp.SEC;
		tmp=rankundo.back();
		rankundo.POB();
		ran[tmp.FIR]=tmp.SEC;
	}
	mp root(int now){
		if(fa[now]==now) return II(now,0);
		mp ret=root(fa[now]);
		ret.second ^= pa[now];
		return ret;
	}
	void merge(int u,int v){
		mp ru,rv;
		ru=root(u);
		rv=root(v);
		if(ru.FIR==rv.FIR){
			if(ru.SEC==rv.SEC&&isok){
				isok=false;
				okundo.PB(1);
			}
			else{
				okundo.PB(0);
			}
			fatherundo.PB({0,0});
			parityundo.PB({0,0});
			rankundo.PB({0,0});
			return ;
		}
		if(ran[ru.FIR]>ran[rv.FIR]){
			swap(u,v);
			swap(ru,rv);
		}
		// u->v
		fatherundo.PB({ru.first,ru.first});
		rankundo.PB({rv.first,ran[rv.first]});
		parityundo.PB({ru.first,0});
		okundo.PB(0);
		if(ran[ru.FIR]==ran[rv.first]){
			ran[rv.first]++;
		}
		fa[ru.FIR]=rv.first;
		pa[ru.first]=ru.second^1^rv.second;
	}
}dsu;
int n,q;
const int N=1<<17;
vector<mp> tree[N+N];
int answer[N+1];
void add(int a,int b,mp val,int now=1,int l=1,int r=N+1){
	if(r<=a||l>=b){
		return;
	}
	if(r<=b&&l>=a){
		tree[now].PB(val);
		return;
	}
	int mid=(l+r)>>1;
	add(a,b,val,now<<1,l,mid);
	add(a,b,val,now<<1|1,mid,r);
}
void run(int now=1,int l=1,int r=N+1){
	for(auto it:tree[now]){
		dsu.merge(it.FIR,it.SEC);
	}
	if(l==r-1){
		answer[l]=dsu.isok;
	}
	else{
		int mid=(l+r)>>1;
		run(now<<1,l,mid);
		run(now<<1|1,mid,r);
	}
	rep(i,tree[now].size())
		dsu.undo();
}
map<mp,int> s;
int main(){
	scanf("%d%d",&n,&q);
	rb(i,1,q){
		int u,v;
		scanf("%d%d",&u,&v);
		if(s.find(II(u,v))!=s.end()){
			int a=s[II(u,v)];
			add(a,i,II(u,v)); 
			s.erase(II(u,v));
		}
		else{
			s[II(u,v)]=i;
		}
	}
	for(auto ite=s.begin();ite!=s.end();++ite){
		add(ite->SEC,q+1,ite->FIR);
	}
	run();
	rb(i,1,q){
		puts(answer[i]? "YES":"NO");
	}
	return 0;
}