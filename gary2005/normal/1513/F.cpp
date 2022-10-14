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
const int MAXN=4e5+233;
int n,a[MAXN],b[MAXN];
vector<int> v;
vector<int> e[MAXN][2];
multiset<int> se[2];
int fnd(int x){	return lower_bound(ALL(v),x)-v.begin()+1;}
int main(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&a[i]),v.PB(a[i]);
	rb(i,1,n) scanf("%d",&b[i]),v.PB(b[i]);
	LL rest=0;
	rb(i,1,n) rest+=abs(a[i]-b[i]);
	LL sum=rest;
	sort(ALL(v));v.erase(unique(ALL(v)),v.end());
	rb(i,1,n) e[fnd(min(b[i],a[i]))][a[i]>b[i]].PB(1),e[fnd(max(a[i],b[i]))+1][a[i]>b[i]].PB(-min(b[i],a[i]));
	rb(i,1,v.size()){
		rep(j,2){
			for(auto it:e[i][j]){
				if(it==1) se[j].insert(v[i-1]);
				else se[j].erase(se[j].find(-it));
			}
		}
		if(!se[0].empty()&&!se[1].empty()) check_min(rest,sum-2ll*(v[i-1]-max(*se[0].begin(),*se[1].begin())));
	}
	printf("%lld\n",rest);
	return 0;
}