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
const int MAXN=3e5+233;
int t,n,m,x[MAXN];
char c[MAXN];
int rest[MAXN];
bool cmp(pair<int,pair<int,char> >  A,pair<int,pair<int,char> >  B){
	return A.SEC.FIR<B.SEC.FIR;
}
void solve(){
	scanf("%d%d",&n,&m);
	fill(rest+1,rest+1+n,-1);
	rb(i,1,n) scanf("%d",&x[i]);
	rb(i,1,n) cin>>c[i];
	vector<pair<int,pair<int,char > > > v[2];
	rb(i,1,n) v[x[i]&1].PB(II(i,II(x[i],c[i]))); 
	rep(i,2){
		sort(ALL(v[i]),cmp);
		vector<pair<int,pair<int,char> > > sta;
		vector<pair<int,pair<int,char> > > vv;
		for(auto it:v[i]){
			if(it.SEC.SEC=='L'){
				if(!sta.empty()){
					auto tmp=sta.back();
					rest[it.FIR]=rest[tmp.FIR]=(it.SEC.FIR-tmp.SEC.FIR)/2;
					sta.POB();
				}
				else{
					vv.PB(it);
				}
			}
			else{
				sta.PB(it);
			}
		}
		reverse(ALL(vv));
		while(vv.size()>=2){
			auto tmp1=vv.back();
			vv.POB();
			auto tmp2=vv.back();
			vv.POB();
			rest[tmp1.FIR]=rest[tmp2.FIR]=tmp1.SEC.FIR+(tmp2.SEC.FIR-tmp1.SEC.FIR)/2;
		}
		while(sta.size()>=2){
			auto tmp1=sta.back();
			sta.POB();
			auto tmp2=sta.back();
			sta.POB();
			rest[tmp1.FIR]=rest[tmp2.FIR]=m-tmp1.SEC.FIR+(tmp1.SEC.FIR-tmp2.SEC.FIR)/2;
		}
		if(sta.size()&&vv.size()){
			auto tmp1=vv.back();
			auto tmp2=sta.back();
			rest[tmp1.FIR]=rest[tmp2.FIR]=m-(tmp2.SEC.FIR-tmp1.SEC.FIR)/2;
		}
	}
	rb(i,1,n) printf("%d ",rest[i]);
	cout<<endl;
}
int main(){
	cin>>t;
	while(t--) solve();
	return 0;
}