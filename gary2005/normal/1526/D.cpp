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
const int MAXN=1e5+233;
int bit[MAXN];
int n;
void add(int pos,int val){
	while(pos<=n){
		bit[pos]+=val;
		pos+=pos&-pos;
	}
}
int query(int pos){
	int s=0;
	while(pos){
		s+=bit[pos];
		pos-=pos&-pos;
	}
	return s;
}
string s;
void solve(){
	cin>>s;
	vector<int> V[4];
	n=s.length();
	int id[4];
	rep(i,4) id[i]=i;
	rep(i,n){
		if(s[i]=='A') V[0].PB(i+1);
		if(s[i]=='N') V[1].PB(i+1);
		if(s[i]=='T') V[2].PB(i+1);
		if(s[i]=='O') V[3].PB(i+1);
	}
	pair<LL,string> ans;
	ans.FIR=-1;
	ans.SEC="FUCK";
	do{
		vector<int> vv;
		string Tmp;
		rep(i,4)
			for(auto it:V[id[i]]){
				if(id[i]==0) Tmp.PB('A');
				if(id[i]==1) Tmp.PB('N');
				if(id[i]==2) Tmp.PB('T');
				if(id[i]==3) Tmp.PB('O');
				vv.PB(it);
			}
		fill(bit+1,bit+1+n,0);
		LL tmp=0;
		int cnt=0;
		for(auto it:vv){
			tmp+=cnt-query(it);
			cnt++;
			add(it,1);
		}
		check_max(ans,II(tmp,Tmp));
	}while(next_permutation(id,id+4));
	cout<<ans.SEC<<endl;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}