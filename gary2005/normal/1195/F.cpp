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
int n;
vector<mp> L[100000+233];
map<mp,int> m;
int l[100000+233],r[100000+233];
int a[300000+233];
int ans[300000+233];
int lst[300000+233];
int pre[300000+233];
const int MAXN=300000+233;
int bit[MAXN+10]={0};
int sum(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i-=i&(-i);
	}
	return s;
}
void add(int i,int x=1){
	while(i<=MAXN){
		bit[i]+=x;
		i+=i&(-i);	
	}
}
int main(){
	scanf("%d",&n);
	rb(i,1,n){
		int ki;
		scanf("%d",&ki);
		vector<mp> pt;
		rb(j,1,ki){
			int x,y;
			scanf("%d%d",&x,&y);
			pt.PB({x,y});
		} 
		pt.PB(pt.front());
		rep(j,ki){
			int x,y;
			x=pt[j+1].FIR-pt[j].FIR;
			y=pt[j+1].SEC-pt[j].SEC;
			int g=abs(__gcd(x,y));
			x/=g;
			y/=g;
			L[i].PB({x,y});
			m[{x,y}]=1;
		}
	}
	int cnt=0;
	for(auto ite=m.begin();ite!=m.end();++ite) ite->SEC=++cnt;
	cnt=0;
	rb(i,1,n){
		vector<int> v;
		for(auto it:L[i]){
			v.PB(m[it]);
		}
		sort(ALL(v));
		v.erase(unique(ALL(v)),v.end());
		l[i]=cnt+1;
		r[i]=cnt+v.size();
		for(auto it:v) a[++cnt]=it;
	}
	vector<mp> iq;
	rb(i,1,cnt){
		lst[i]=pre[a[i]];
		pre[a[i]]=i;
		iq.PB({lst[i],i});
	}
	vector<pair<mp,int> > queries;
	int q;
	scanf("%d",&q);
	rb(T,1,q){
		int l_,r_;
		scanf("%d%d",&l_,&r_);
		queries.PB({{l[l_],r[r_]},T});
	}
	int now=0;
	sort(ALL(queries));
	sort(ALL(iq));
	for(auto it:queries){
		while(now!=iq.size()&&iq[now].FIR<it.FIR.FIR){
			add(iq[now].SEC);
			now++;
		}
		ans[it.SEC]=sum(it.FIR.SEC)-sum(it.FIR.FIR-1);
	}
	rb(i,1,q){
		printf("%d\n",ans[i]);
	}
	return 0;
}