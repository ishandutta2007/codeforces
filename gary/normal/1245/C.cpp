/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
6.long double | 
7.!(prince and princess)
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
string s;
const int MOD=1e9+7;
LL dp[200000];
int main(){
	cin>>s;
	dp[0]=1;
	dp[1]=1;
	dp[2]=2;
	rb(i,3,100000){
		dp[i]=dp[i-1]+dp[i-2];
		dp[i]%=MOD;
	}
	int OK=1;
	int len=s.length();
	rep(i,len){
		if(s[i]=='m'||s[i]=='w'){
			OK=0;
		}
	}
	if(!OK){
		puts("0");
		return 0;
	}
	int cnt=0;
	char las='&';
	LL res=1;
	rep(i,len){
		if(s[i]!='u'&&s[i]!='n'){
			res*=dp[cnt];
//			cout<<cnt<<endl;
			res%=MOD;
			cnt=0;
			las='&';
			continue;
		}
		else{
			if(s[i]==las){
				cnt++;
			}
			else{
				res*=dp[cnt];
				res%=MOD;
				cnt=1;
				las=s[i];
			}
		}
	}
	res*=dp[cnt];
	res%=MOD;
	cout<<res<<endl;
	return 0;
}