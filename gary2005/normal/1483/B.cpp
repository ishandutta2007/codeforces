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
int a[100000+233];
int pre[100000+233],nex[100000+233];
set<int> can;
int findnex(int pos){
	if(can.upper_bound(pos)!=can.end()) return *can.upper_bound(pos);
	return *can.begin();
}
void solve(){
	scanf("%d",&n);
	rb(i,1,n){
		scanf("%d",&a[i]);	
	}
	rb(i,1,n){
		if(i==1) pre[i]=n;
		else pre[i]=i-1;
		if(i==n) nex[i]=1;
		else nex[i]=i+1;
	}
	can.clear();
	rb(i,1,n){
		if(__gcd(a[i],a[nex[i]])==1){
			can.insert(nex[i]);
		}
	}
	int now=1;
	vector<int> rest;
	while(!can.empty()&&rest.size()!=n){
		int era=findnex(now);
		now=nex[era];
		can.erase(era);
		rest.PB(era);
		pre[nex[era]]=pre[era];
		nex[pre[era]]=nex[era];
		if(can.find(nex[era])!=can.end()) can.erase(nex[era]);
		if(__gcd(a[nex[era]],a[pre[era]])==1){
			can.insert(nex[era]);
		}
	}
	cout<<rest.size()<<" ";
	for(auto it:rest) printf("%d ",it);
	puts("");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}