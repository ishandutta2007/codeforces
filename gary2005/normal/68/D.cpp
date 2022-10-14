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
unordered_map<int,int> sum;
int h,q;
double getdp(int v,int rest){
	if(v>=(1<<h)) return max(rest,sum[v]);
	if(rest>=sum[v]) return rest;
	return 0.5*(getdp(v<<1,max(rest,sum[v]-sum[v<<1]))+getdp(v<<1|1,max(rest,sum[v]-sum[v<<1|1])));
}
int main(){
	scanf("%d%d",&h,&q);
	rb(i,1,q){
		string ty;
		cin>>ty;
		if(ty[0]=='a'){
			int v,c;
			scanf("%d%d",&v,&c);
			while(v){
				sum[v]+=c;
				v>>=1;
			}
		}
		else{
			printf("%.10f\n",getdp(1,0));
		}
	}
	return 0;
}