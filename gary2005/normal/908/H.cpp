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
void FMT(int* A,int n){
	rep(i,n)
		rep(j,(1<<n))
			if(j&(1<<i)) A[j]+=A[j^(1<<i)];
}
int tmp[1<<23];
int dp[1<<23];
int can[1<<23];
bool check(int n){
	int ret=0;
	int all=(1<<n)-1;
	rep(i,(1<<n)){
		int z=__builtin_popcount(i)&1;
		if(z){
			ret-=dp[all^i];
		}
		else{
			ret+=dp[all^i];
		}
	}
	return ret;
}
char e[47][47];
int fa[47];
int siz[47];
bool edge[23][23];
int root(int now){
	return fa[now]=(fa[now]==now? now:root(fa[now])); 
}
int main(){
	int n;
	scanf("%d",&n);
	rep(i,n) rep(j,n) cin>>e[i][j];
	rep(i,n) fa[i]=i;
	rep(i,n) rep(j,n) if(e[i][j]=='A'){
		fa[root(i)]=root(j);
	}
	rep(i,n) rep(j,n) if(e[i][j]=='X'&&root(i)==root(j)) {puts("-1");return 0;}
	rep(i,n) siz[root(i)]++;
	int num=0;
	int Cn=0;
	vector<int> id;
	
	
	rep(i,n) if(root(i)==i){
		++Cn;
		if(siz[i]>1){
			num+=siz[i];
			id.PB(i);
		}
	}
	int n2=id.size();
	rep(i,n) rep(j,n) if(e[i][j]=='X'){
		int i_,j_;
		i_=root(i);
		j_=root(j);
		if(siz[i_]==1||siz[j_]==1) continue;
		i_=lower_bound(ALL(id),i_)-id.begin();
		j_=lower_bound(ALL(id),j_)-id.begin();
		edge[i_][j_]=1;
	}
	rep(mask,1<<n2){
		can[mask]=1;
		rep(j,n2)
			if((mask>>j)&1){
				rep(k,n2)
					 if((mask>>k)&1)
					 	if(edge[j][k]){
					 		can[mask]=false;
					 		break;
						}
				if(!can[mask]) break;
			}
	}
	num+=Cn-1;
	dp[0]=1;
	FMT(can,n2);
	FMT(dp,n2);
	rb(i,1,n2){
		rep(mask,1<<n2)
			dp[mask]=dp[mask]*can[mask];
		if(check(n2)){
			num-=(n2-i);
			break;
		}
	}
	cout<<num<<endl;
	return 0;
}