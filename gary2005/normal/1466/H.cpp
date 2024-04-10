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
const int MAXN=44;
int fa[MAXN];
map<mp,int> M;
vector<vector<int> > allv;
int n,a[MAXN];
int root(int x){
	if(fa[x]==x) return x;
	return root(fa[x]);
}
int val[44];
mp myhash(vector<int> v){
	mp ret=II(666,233);
	int mul1,mul2,mod1,mod2;
	mul1=1e9+7;
	mod1=19260817;
	mul2=1e9+3;
	mod2=66662333;
	for(auto it:v){
		ret.FIR=1ll*ret.FIR*mul1%mod1;
		ret.SEC=1ll*ret.SEC*mul2%mod2;
		(ret.FIR+=val[it])%=mod1;
		(ret.SEC+=val[it])%=mod2;
	}
	return ret;
}
int id(vector<int> v){
	return M[myhash(v)];
}
vector<mp> v;
const int MOD=1e9+7;
int fact[MAXN],ifact[MAXN];
vector<int> tonow;
int Cnt=0;
void dfs(int now){
	if(now==v.size()){
		allv.PB(tonow);
		M[myhash(tonow)]=++Cnt;
		return ;
	}
	rb(i,0,v[now].SEC){
		tonow.PB(i);
		dfs(now+1);
		tonow.POB();
	}
}
LL quick(LL A,LL B){
	if(B==0) return 1;
	LL  tmp=quick(A,B>>1);
	tmp*=tmp;
	tmp%=MOD;
	if(B&1)
		tmp*=A,tmp%=MOD;
 	return tmp;
}
int inv(int x){
	return quick(x,MOD-2);
}
void add(int & A,int B){
	A+=B;
	if(A>=MOD) A-=MOD;
}
int c(int A,int B){
	return 1ll*fact[A]*ifact[B]%MOD*ifact[A-B]%MOD;
}
struct state{
	int to,pre,sum,k;
	bool operator < (const state &oth) const {
		return II(II(to,pre),II(sum,k))<II(II(oth.to,oth.pre),II(oth.sum,oth.k));
	}
	bool operator == (const state &oth) const {
		return II(II(to,pre),II(sum,k))==II(II(oth.to,oth.pre),II(oth.sum,oth.k));	
	}
	int getpresum(){
		vector<int> V=allv[k-1];
		int rest=0;
		rep(i,V.size()) rest+=V[i]*v[i].FIR;
		return rest-sum;
	}
	state(){}
	state(int A,int B,int C,int D){
		to=A,pre=B,sum=C,k=D;
	}
};
map<state,int> dp;
void debug(state now,int val){
	cout<<"{"<<now.to<<','<<now.sum<<' '<<now.pre<<"___"<<now.k<<'[';
	for(auto it:allv[now.k-1]) cout<<it<<',';
	cout<<"]:"<<val<<endl;
}
int calc(int have,int len){
	int tmp=0;
	rb(i,0,have){
		(tmp+=1ll*c(have,i)*fact[i]%MOD*fact[n-i-1]%MOD)%=MOD;
	}
	return quick(tmp,len);
}
int calc(state now){
	if(dp.find(now)!=dp.end()) return dp[now];
	int to,pre,sum,k;
	to=now.to,pre=now.pre,sum=now.sum,k=now.k; 
	vector<int> nowv,nv;
	int nto,npre,nsum,nk;
	int presum=now.getpresum();
	dp[now]=0;
	if(presum+sum==n){
		dp[now]=1;
		return dp[now];
	}
	nv=nowv=allv[k-1];
	if(to!=v.size()-1){
		dp[now]=calc(state(to+1,pre,sum,k));
		int i=to+1;
		int rst=v[i].SEC-nowv[i];
		int one=(calc(presum,v[i].FIR)-calc(presum-pre,v[i].FIR)+MOD)%MOD;
		if(pre==0) one=calc(0,v[i].FIR);
		rb(j,1,rst){
			int tmp=quick(one,j);
			tmp=1ll*tmp*c(rst,j)%MOD;
			nto=i;
			npre=pre;
			nsum=sum+j*v[i].FIR;
			nv[i]+=j;
			nk=id(nv);
			nv[i]-=j;
			dp[now]+=1ll*tmp*calc(state(nto,npre,nsum,nk))%MOD;
			dp[now]%=MOD;
		}
	}
	else
	if(sum){
		dp[now]+=calc(state(-1,sum,0,k));
		dp[now]%=MOD;
	}
	return dp[now];
}
int main(){
	SRAND;
	scanf("%d",&n);
	fact[0]=1;
	rb(i,1,n) fact[i]=1ll*fact[i-1]*i%MOD;
	ifact[n]=quick(fact[n],MOD-2);
	rl(i,n-1,0) ifact[i]=1ll*(i+1)*ifact[i+1]%MOD;
	rep(i,n) val[i]=random(998244853);
	rb(i,1,n) scanf("%d",&a[i]);
	rb(i,1,n) fa[i]=i;
	rb(i,1,n) fa[root(i)]=root(a[i]);
	int siz[MAXN]={0};
	int cnt[MAXN]={0};
	rb(i,1,n) siz[root(i)]++;
	rb(i,1,n) if(root(i)==i) cnt[siz[i]]++;
	rb(i,1,n) if(cnt[i]) v.PB(II(i,cnt[i]));
	dfs(0);
	cout<<calc(state(-1,0,0,1));
	return 0;
}