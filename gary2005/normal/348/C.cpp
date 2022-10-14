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
int n,m,q;
const int MAXN=1e5+233;
const int MAGIC=233;
vector<vector<int> > se;
vector<int> bigset;
LL a[MAXN];
LL delta[MAXN];
LL sum[MAXN];
int mark[MAXN];
vector<vector<int> > com;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	rb(i,1,n) scanf("%lld",&a[i]);
	se.resize(m+1);
	rb(i,1,m){
		int k;
		scanf("%d",&k);
		int ai;
		rb(j,1,k){
			scanf("%d",&ai);
			se[i].PB(ai);
			sum[i]+=a[ai];
		}
		if(se[i].size()>=MAGIC){
			bigset.PB(i);
		}
	}
	com=vector<vector<int> > (bigset.size(),vector<int> (m+2));
	rep(i,bigset.size()){
		memset(mark,0,sizeof(mark));
		for(auto it:se[bigset[i]])
			mark[it]=1;
		rb(j,1,m)
			for(auto it:se[j])
				com[i][j]+=mark[it];	
	}
	rb(i,1,q){
		char t;
		cin>>t;
		if(t=='?'){
			int x;
			scanf("%d",&x);
			LL rest=0;
			if(se[x].size()>=MAGIC)
				rest=sum[x];
			else{
				for(auto it:se[x]){
					rest+=a[it];
				}
			}
			rep(i,bigset.size()){
				rest+=delta[bigset[i]]*com[i][x];
			}
			printf("%lld\n",rest);
		}
		else{
			int x,y;
			scanf("%d%d",&x,&y);
			if(se[x].size()>=MAGIC){
				delta[x]+=y;
			}
			else{
				rep(i,bigset.size()){
					sum[bigset[i]]+=1ll*y*com[i][x];
				}
				for(auto it:se[x]) a[it]+=y;
			}
		}
	}
	return 0;
}