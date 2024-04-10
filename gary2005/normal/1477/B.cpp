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
int n,q;
set<pair<mp,int> > ss,ts;
void upd(int pt,bool ty){
	auto ite=ss.upper_bound(II(II(pt,INF),INF));
	--ite;
	if((ty&&(ite->FIR).FIR==pt)||(!ty&&(ite->FIR).SEC==pt));
	else{
		pair<mp,int> z=*ite;
		ss.erase(ite);
		ss.insert({{z.FIR.FIR,pt-ty},z.SEC});
		ss.insert({{pt+(!ty),z.FIR.SEC},z.SEC});
	}
}
bool get(int l,int r){
	upd(l,1);
	upd(r,0);
	auto ite=ss.upper_bound(II(II(l,-INF),-INF));
	auto nex=ite;
	int one=0;
	while(ite!=ss.end()&&(ite->FIR).SEC<=r){
		one+=(ite->SEC)*((ite->FIR).SEC-(ite->FIR).FIR+1);
		++ite;
	}
	ite=ss.upper_bound(II(II(l,-INF),-INF));
	if(one==(r-l+1)/2&&(r-l+1)%2==0) return false;
	int zero=r-l+1-one;
	int is;
	if(zero>one) is=0;
	else is=1;
	while(ite!=ss.end()&&(ite->FIR).SEC<=r){
		nex=++ite;
		--ite;
		ss.erase(ite);
		ite=nex;
	}
	ss.insert({{l,r},is});
	return true;
}
void solve(){
	scanf("%d%d",&n,&q);
	string s,t;
	cin>>t>>s;
	vector<mp> seg;
	rb(i,1,q){
		int l,r;
		scanf("%d%d",&l,&r);
		seg.PB({l,r});
	}
	reverse(ALL(seg));
	ss.clear();
	ts.clear();
	for(int i=0;i<n;++i){
		int j;
		for(j=i;j<n&&s[j]==s[i];++j);
		--j;
		ss.insert(II(II(i+1,j+1),s[i]-'0'));
		i=j;
	}
	for(int i=0;i<n;++i){
		int j;
		for(j=i;j<n&&t[j]==t[i];++j);
		--j;
		ts.insert(II(II(i+1,j+1),t[i]-'0'));
		i=j;
	}
	bool ok=1;
	for(auto it:seg){
		ok&=get(it.FIR,it.SEC);
		if(!ok) break;
	}
	for(auto ite=ss.begin();ite!=ss.end();++ite){
		rb(j,ite->FIR.FIR,ite->FIR.SEC){
			s[j-1]='0'+ite->SEC;
		}
	}
	ok&=(t==s);
	cout<<(ok? "YES":"NO")<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}