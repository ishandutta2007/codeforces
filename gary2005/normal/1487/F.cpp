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
char c[5005];
string s;
int dp[2][3][(5004*5+20)*2+1],len,a[5005];
int X[3]={0,1,-1};
int f[400000];
const int B=200000;
void solve(){
	reverse(ALL(s));
	s.PB('0');
	s.PB('0');
	len=s.length();
	rb(i,1,len) a[i]=s[i-1]^48;
	rb(i,1,len) a[i]=9*a[i];
	rb(i,1,len) a[i+1]+=a[i]/10,a[i]%=10;
	reverse(a+1,a+len+1);
	int BB=len*5+20;
	rb(i,-BB,BB) rep(x,2) rep(y,3) dp[x][y][BB+i]=INF;
	dp[0][0][BB]=0;
	rb(i,1,len-5){
		rep(y,3) rb(j,-BB,BB) dp[i&1][y][BB+j]=INF;
		rep(y,3) if(abs(a[i]-10*X[y]-1)<=5||abs(a[i]-10*X[y]+1)<=5) rb(j,-BB,BB) if(dp[(i&1)^1][y][BB+j]!=INF){
			int val=dp[(i&1)^1][y][BB+j];
			int diff=10*X[y];
			for(int pt=a[i]-diff-1;pt<=a[i]-diff+1;pt++){
				if(abs(pt)>5&&i!=1) continue;
				int nw=diff-a[i]+pt;
				if(abs(nw)<=1){
					if(nw==0) nw=0;
					else if(nw==1) nw=1;
					else nw=2;
					if(pt+j<=BB&&pt+j>=-BB)
						check_min(dp[i&1][nw][j+pt+BB],val+abs(pt)*(len-i));
				}
			}
		}
	}
	int t=max(0,len-5);
	int ans=INF;
	int pw10=1;
	rb(i,1,len-t) pw10=10*pw10;
	int xx=0;
	rb(i,t+1,len) xx*=10,xx+=a[i];
	rep(y,3) rb(j,-BB,BB){
		if(dp[t&1][y][j+BB]!=INF){
			check_min(ans,dp[t&1][y][BB+j]+f[200000+X[y]*pw10-xx-j]);
		}
	}
	printf("%d\n",ans);
}
int main(){
	memset(f,63,sizeof(f));
	f[B]=0;
	priority_queue<mp,vector<mp>,greater<mp> > pq;
	pq.push(II(0,B));
	int pw10[100];
	pw10[0]=1;
	rb(i,1,5) pw10[i]=10*pw10[i-1];
	while(!pq.empty()){
		mp now=pq.top();
		pq.pop();
		if(now.FIR!=f[now.SEC]){
			continue;
		}
		rb(i,1,5){
			int nx=now.SEC+pw10[i]-1;
			if(nx<400000&&nx>=0&&f[nx]>now.FIR+i){
				f[nx]=now.FIR+i;
				pq.push(II(now.FIR+i,nx));
			}
			nx=now.SEC-pw10[i]+1;
			if(nx<400000&&nx>=0&&f[nx]>now.FIR+i){
				f[nx]=now.FIR+i;
				pq.push(II(now.FIR+i,nx));
			}
		}
	}
	while(scanf("%s",c)!=EOF){
		s=c;
		solve();
	}
	return 0;
}