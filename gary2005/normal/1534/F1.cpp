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
const int MAXM=4e5+233;
set<int> se[MAXM];
int n,m;
int X,Y;
vector<mp> VV;
void go(int x,int y){
	VV.PB(II(x,y));
	if(se[x].find(y+1)!=se[x].end()){
		if(X!=x||Y!=y+1){
			se[x].erase(y+1);
			go(x,y+1);
		}
	}
	vector<int> pre,now,nex;
	for(auto ite=se[x-1].begin();ite!=se[x-1].end()&&*ite<=y;ite++) pre.PB(*ite);
	for(auto ite=se[x].begin();ite!=se[x].end()&&*ite<=y;ite++) now.PB(*ite);
	for(auto ite=se[x+1].begin();ite!=se[x+1].end()&&*ite<=y;ite++) nex.PB(*ite);
	for(auto it:pre){
		if(se[x-1].find(it)!=se[x-1].end()){
			if(X!=x-1||Y!=it){
				se[x-1].erase(it);
				go(x-1,it);
			}
		}
	}
	for(auto it:nex){
		if(se[x+1].find(it)!=se[x+1].end()){
			if(X!=x+1||Y!=it){
			se[x+1].erase(it);
			go(x+1,it);
			}
		}
	}
	for(auto it:now){
		if(se[x].find(it)!=se[x].end()){
			if(X!=x||Y!=it){
				se[x].erase(it);
				go(x,it);
			}
		}
	}
}
map<mp,int> cnt;
int main(){
	scanf("%d%d",&n,&m);
	vector<vector<char> > v;
	v.resize(n+1);
	rb(i,1,n) v[i].resize(m+1);
	rb(i,1,n){
		rb(j,1,m){
			cin>>v[i][j];
			if(v[i][j]=='#'){
				se[j].insert(n-i+1);
			} 
		}
	}
	rb(i,1,m){
		if(!se[i].empty()){
			int x,y;
			x=i;
			y=*prev(se[i].end());
			if(cnt[II(x,y)]) continue;
			X=x;
			Y=y;
			VV.clear();
			go(x,y);
			rb(j,1,VV.size()-1){
				cnt[VV[j]]++;
				if(cnt[VV[j]]==1){
					se[VV[j].FIR].insert(VV[j].SEC);
				}
			}
		}
	}
	for(auto ite=cnt.begin();ite!=cnt.end();ite++){
		if(ite->SEC==1) se[ite->FIR.FIR].erase(ite->FIR.SEC);
	}
	int ans=0;
	rb(i,1,m){
		ans+=se[i].size();	
	}
	cout<<ans<<endl;
	return 0;
}