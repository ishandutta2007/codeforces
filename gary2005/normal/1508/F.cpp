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
const int MAGIC=125;
unordered_map<int,int> queries[25000+233];
int n,q,a[25000+233],pos[25000+233],l[100000+233],r[100000+233],id[100000+233],ans[100000+233];
vector<int> tol[25000+233],tor[25000+233];
bool cmp(int A,int B){
	if(l[A]/MAGIC==l[B]/MAGIC) return r[A]<r[B];
	return l[A]/MAGIC<l[B]/MAGIC;
}
bool cmp2(int A,int B){
	return II(l[A],r[A])<II(l[B],r[B]);
}
void addedge(int u,int v){
	if(pos[u]<pos[v]) tor[pos[u]].PB(pos[v]);
	if(pos[u]>pos[v]) tol[pos[u]].PB(pos[v]);
}
int bit[25000+233];
void Set(int x,int val){
	while(x<=25000){
		check_min(bit[x],val);
		x+=x&-x;
	}
}
int query(int x){
	int rest=q+1;
	while(x){
		check_min(rest,bit[x]);
		x-=x&-x;
	}
	return rest;
}
void solve(){
	memset(bit,63,sizeof(bit));
	rb(i,1,q) id[i]=i;
	sort(id+1,id+1+q,cmp2);
	int pt=1;
	rb(i,1,n){
		while(pt<=q&&l[id[pt]]<=i){
			Set(n-r[id[pt]]+1,id[pt]);
			++pt;
		}
		for(auto ite=queries[i].begin();ite!=queries[i].end();ite++){
			ite->SEC=query(n-ite->FIR+1);
		}
	}
}
int main(){
	scanf("%d%d",&n,&q);
	rb(i,1,n) scanf("%d",&a[i]),pos[a[i]]=i;
	rb(i,1,q) id[i]=i;
	rb(i,1,q) scanf("%d%d",&l[i],&r[i]);
	sort(id+1,id+1+q,cmp);
	set<int> s;
	int nowl,nowr;
	nowl=nowr=0;
	rb(i_,1,q){
		int i=id[i_];
		while(nowr<r[i]) {
		++nowr;
		s.insert(a[nowr]);
		auto ite=s.find(a[nowr]);
		if(ite!=s.begin()) addedge(*prev(ite),*ite);
		if(next(ite)!=s.end()) addedge(*ite,*next(ite));
		}
		while(nowl<l[i]) {
		if(nowl){
			auto ite=s.find(a[nowl]);
			if(ite!=s.begin()&&next(ite)!=s.end()) addedge(*prev(ite),*next(ite));
			s.erase(a[nowl]);
		}
		++nowl;
		}
		while(nowr>r[i]){
		auto ite=s.find(a[nowr]);
		if(ite!=s.begin()&&next(ite)!=s.end()) addedge(*prev(ite),*next(ite));
		s.erase(a[nowr]);--nowr;
		}
		while(nowl>l[i]) {--nowl;
		s.insert(a[nowl]);
		auto ite=s.find(a[nowl]);
		if(ite!=s.begin()) addedge(*prev(ite),*ite);
		if(next(ite)!=s.end()) addedge(*ite,*next(ite));
		}
	}
	rb(i,1,n) sort(ALL(tol[i])),sort(ALL(tor[i])),tol[i].erase(unique(ALL(tol[i])),tol[i].end()),
	          tor[i].erase(unique(ALL(tor[i])),tor[i].end()),reverse(ALL(tol[i]));
	rb(i,1,n){
		rep(j,tol[i].size()) queries[tol[i][j]][i]=1;
		rep(j,tor[i].size()) queries[i][tor[i][j]]=1;
		int pt=0;
		rep(j,tol[i].size()){
			while(pt<tor[i].size()&&a[tor[i][pt]]>a[tol[i][j]]) ++pt;
			if(pt<tor[i].size()) queries[min(tol[i][j],tor[i][pt])][max(tol[i][j],tor[i][pt])]=1;
		}
		pt=0;
		rep(j,tor[i].size()){
			while(pt<tol[i].size()&&a[tol[i][pt]]>a[tor[i][j]]) ++pt;
			if(pt<tol[i].size()) queries[min(tor[i][j],tol[i][pt])][max(tor[i][j],tol[i][pt])]=1;
		}
	}
	int cnt=0;
	rb(i,1,n) cnt+=tor[i].size()+tol[i].size();
	solve();
	rb(i,1,n){
		int pt=0;
		rep(j,tol[i].size()){
			int Z=q+1;
			while(pt<tor[i].size()&&a[tor[i][pt]]>a[tol[i][j]]) ++pt;
			if(pt<tor[i].size()) check_min(Z,queries[min(tol[i][j],tor[i][pt])][max(tol[i][j],tor[i][pt])]);
			if(j!=tol[i].size()-1) check_min(Z,queries[tol[i][j+1]][i]);
			if(Z>queries[tol[i][j]][i]){
				ans[queries[tol[i][j]][i]]++;
				ans[Z]--;
			}
		}
		pt=0;
		rep(j,tor[i].size()){
			int Z=q+1;
			while(pt<tol[i].size()&&a[tol[i][pt]]>a[tor[i][j]]) ++pt;
			if(pt<tol[i].size()) check_min(Z,queries[min(tor[i][j],tol[i][pt])][max(tor[i][j],tol[i][pt])]);
			if(j!=tor[i].size()-1) check_min(Z,queries[i][tor[i][j+1]]);
			if(Z>queries[i][tor[i][j]]){
				ans[queries[i][tor[i][j]]]++;
				ans[Z]--;
			}
		}
	}
	int rest=0;
	rb(i,1,q){
		rest+=ans[i];
		printf("%d\n",rest);
	}
	return 0;
}