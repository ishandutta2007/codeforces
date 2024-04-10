/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize(2)
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
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
#define int LL
const int MOD=1e9+7;
int n,sum[100002][4],sqsum[100002][4],cnt[100002][4],s[100002],ten[200002];
int solve(string l,string r){
	n=r.length();
	memset(sum,0,sizeof(sum)),memset(sqsum,0,sizeof(sqsum)),memset(cnt,0,sizeof(cnt));
	cnt[0][3]=1;
	rb(i,1,n){
	int num=r[i-1]^48;
			  int numl=l[i-1]^48;
		rep(jl,2) 
		rep(j,2){
			int mask=(j)|(jl<<1);
			for(int jj=4;jj<=7;jj+=3){
				if(j&&(jj>num)) break;
				if(jl&&jj<numl){
//					cout<<jj<<" "<<numl<<" "<<jl<<' '<<j<<endl; 
					continue;	
				} 
				int new_j=((j&(jj==num)))|((jl&(jj==numl))<<1);
//				cout<<new_j<<' '<<mask<<' '<<jj<<' '<<j<<' '<<jl<<' '<<numl<<endl;
				(cnt[i][new_j]+=cnt[i-1][mask])%=MOD;
				(sum[i][new_j]+=(1ll*cnt[i-1][mask]*jj%MOD+10ll*sum[i-1][mask]))%=MOD;
				(sqsum[i][new_j]+=(100ll*sqsum[i-1][mask]+20ll*jj*sum[i-1][mask]+1ll*jj*jj*cnt[i-1][mask]))%=MOD;	
			}
		}
	}
	int rest=0;
//	cout<<cnt[2][3]<<endl;
	rb(i,1,n){
		int tmp=0,A,B;
		bool smaller=(r[i-1]=='7');
		A=7ll*ten[n-i]%MOD+4ll*s[n-i]%MOD;A%=MOD;
		B=4ll*ten[n-i]%MOD+7ll*s[n-i]%MOD;B%=MOD;
		int Sum=sum[i-1][0],Sqsum=sqsum[i-1][0],Cnt=cnt[i-1][0];
		if(smaller){Sum+=sum[i-1][1],Sqsum+=sqsum[i-1][1],Cnt+=cnt[i-1][1];Sum%=MOD,Sqsum%=MOD,Cnt%=MOD;}
//		cout<<tmp<<endl;
		if((l[i-1]=='4')){
//			cout<<'!'<<endl;
//			cout<<Sum<<' '<<Sqsum<<' '<<Cnt<<endl;
			Sum+=sum[i-1][2];
			Sqsum+=sqsum[i-1][2];
			Cnt+=cnt[i-1][2];Sum%=MOD,Sqsum%=MOD,Cnt%=MOD;
//			cout<<Sum<<' '<<Sqsum<<' '<<Cnt<<endl;
			if(smaller){Sum+=sum[i-1][3],Sqsum+=sqsum[i-1][3],Cnt+=cnt[i-1][3];Sum%=MOD,Sqsum%=MOD,Cnt%=MOD;}
		}
		(tmp+=(1ll*Sqsum*ten[(n-i+1)*2]%MOD))%=MOD;
		(tmp+=(1ll*Sum*A%MOD+1ll*Sum*B%MOD)*ten[n-i+1]%MOD)%=MOD;
		(tmp+=1ll*A*B%MOD*Cnt%MOD)%=MOD;
		(rest+=tmp)%=MOD;
//		cout<<tmp<<endl;
	}
	return rest;
}
signed main(){
	fastio;
	string l,r;
	s[0]=0;
	s[1]=1;
	ten[0]=1;
	ten[1]=10;
	rb(i,2,100000)
		s[i]=(10ll*s[i-1]+1)%MOD;
	rb(i,2,200000)
		ten[i]=(10ll*ten[i-1])%MOD;
	cin>>l>>r;
	cout<<solve(l,r)<<endl;	
	return 0;
}