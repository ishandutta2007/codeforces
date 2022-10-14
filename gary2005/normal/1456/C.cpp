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
vector<int> v;
vector<LL> suf;
vector<LL> ssf;
int main(){
	scanf("%d%d",&n,&k);
	rb(i,1,n){
		int ai;
		scanf("%d",&ai);
		v.PB(ai);
	}
	sort(ALL(v));
	LL rest=0;
	if(k==0){
		rep(i,n)
			rest+=1ll*i*v[i];
	}
	else{
		suf.resize(n+2);
		suf[n-1]=v[n-1];
		rl(i,n-2,0)
			suf[i]=suf[i+1]+v[i];
		ssf.resize(n+2);
		ssf[n-1]=0;
		rl(i,n-2,0)
			ssf[i]=ssf[i+1]+suf[i+1];
		priority_queue<int,vector<int>,greater<int> > pq;
		rb(i,1,k+1) pq.push(0);
		LL pre=0;
		rest=-1e18;
		ssf[n]=0;
		suf[n]=0;
		rep(i,n+1){
			int now=pq.top();
			pq.pop();
			check_max(rest,ssf[i]+1ll*now*suf[i]+pre);
			pre+=1ll*now*v[i];
			pq.push(now+1);
		}
	}
	cout<<rest<<endl; 
	return 0;
}