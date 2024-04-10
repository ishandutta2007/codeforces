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
const int MOD=1e9+7;
int n,k;
LL quick(LL A,LL B){
	if(B==0) return 1;
	LL  tmp=quick(A,B>>1);
	tmp*=tmp;
	tmp%=MOD;
	if(B&1)
		tmp*=A,tmp%=MOD;
 	return tmp;
}
int fact[100000+20],invfact[100000+20];
int suf[100000+20];
int tot;
int rest=0;
LL c(int A,int B){
	if(B==0) return 1;
	if(B<0) return 0;
	if(A<B) return 0;
	return 1ll*fact[A]*invfact[A-B]%MOD*invfact[B]%MOD;
}
int main(){
	scanf("%d%d",&n,&k);
	string s;
	cin>>s;
	rl(i,n-1,1)	
		suf[i]=suf[i+1]+(s[i-1]-'0');
	fact[0]=1;
	rb(i,1,n){
		fact[i]=1ll*fact[i-1]*i%MOD;
	}
	invfact[n]=quick(fact[n],MOD-2);
	rl(i,n-1,0)
		invfact[i]=1ll*invfact[i+1]*(i+1)%MOD;
	tot=0;
	int bad=0,ten=1;
	rb(i,1,n-2){
		tot-=bad;
		tot+=MOD;
		tot%=MOD;
		tot=10ll*tot%MOD;
		bad+=1ll*ten*(s[n-1-i]-'0')%MOD;
		bad%=MOD;
		ten=10ll*ten%MOD;
		(tot+=suf[i+1])%=MOD; 
		(rest+=1ll*tot*c(n-2-i,k-2)%MOD)%=MOD;
	}
	int tmp=0;
	rb(i,1,n-1){
		tmp=10ll*tmp%MOD;
		(tmp+=(s[i-1]-'0'))%=MOD;
		(rest+=1ll*tmp*c(n-1-i,k-1)%MOD)%=MOD;
	}
	int z=1;
	tmp=0;
	rb(i,1,n){
		(tmp+=1ll*(s[n-i]-'0')*z%MOD)%=MOD;
		z=10ll*z%MOD;
		(rest+=1ll*tmp*c(n-1-i,k-(i!=n))%MOD)%=MOD;
	}
	cout<<rest<<endl;
	return 0;
}