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
int n,u,r;
vector<int> ope;
int a[33],b[33],k[33],p[33];
LL rest=-1e18;
void run(){
	int tmpa[33];
	rb(i,1,n) tmpa[i]=a[i];
	for(auto it:ope){
		if(it==1){
			rb(i,1,n) tmpa[i]^=b[i];
		}
		else{
			int na[33];
			rb(i,1,n) na[i]=tmpa[p[i]]+r; 
			rb(i,1,n) tmpa[i]=na[i];
		}
	}
	LL tmp=0;
	rb(i,1,n) tmp+=1ll*tmpa[i]*k[i];
	check_max(rest,tmp);
}
void dfs(){
	if((u-ope.size())%2==0){
		run();
		if(ope.size()==u) return ;
	}
	if(ope.empty()||ope.back()!=1){
		ope.PB(1);
		dfs();
		ope.POB();
	}
	ope.PB(2);
	dfs();
	ope.POB();
}
int main(){
	scanf("%d%d%d",&n,&u,&r);
	rb(i,1,n) cin>>a[i];
	rb(i,1,n) cin>>b[i];
	rb(i,1,n) cin>>k[i];
	rb(i,1,n) cin>>p[i];
	dfs();
	cout<<rest<<endl;
	return 0;
}