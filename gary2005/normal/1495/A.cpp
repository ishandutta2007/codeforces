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

void solve(){
	scanf("%d",&n);
	vector<double> v,v2;
	rb(i,1,2*n){
		int x,y;
		scanf("%d%d",&x,&y);
		x=abs(x);
		y=abs(y);
		if(x==0) v.PB(y);
		else v2.PB(x);
	}
	sort(ALL(v));
	sort(ALL(v2));
	int now=0;
	double rest=0;
	rep(i,n){
		rest+=sqrt(v[i]*v[i]+v2[i]*v2[i]); 
	}
	printf("%.10f\n",rest);
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}