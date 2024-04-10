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
int n,k;
int p[200000+20];
vector<int> v;
void solve(int l,int r,int a,int b){
	if(l>r) return;
	if(p[l]){
		if(p[l]>b||p[l]<a){
			cout<<"-1";
			exit(0);
		}
		v.PB(p[l]);
		int len=p[l]-a;
		solve(l+1,l+len,a,p[l]-1);
		solve(l+1+len,r,p[l]+1,b);
	}
	else{
		rl(i,b,a){
			v.PB(i);
		}
	}
}
int main(){
	cin>>n>>k;
	rb(i,1,k) cin>>p[i];
	solve(1,n,1,n);
	for(auto it:v) cout<<it<<' ';
	return 0;
}