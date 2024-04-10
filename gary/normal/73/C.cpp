//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
string s,tmp;
int K;
int n;
int c[27][27];
int dp[105][27][101];
int res=-INF;
int main(){
	memset(dp,-1,sizeof(dp));
	cin>>tmp>>K;
	int len=tmp.length();
	s=" ";
	s+=tmp;
	cin>>n;
	rep(i,n){
		char A,B;
		int temp;
		cin>>A>>B>>temp;
		c[A-'a'+1][B-'a'+1]=temp;
	}
	rb(i,1,26){
		if(s[1]-'a'+1!=i) dp[1][i][1]=0;
		else dp[1][i][0]=0;
	}
	if(len==1) res=0;
	rb(i,1,len){
		rb(j,1,26){
			rb(k,0,K)
			{	
				if(dp[i][j][k]==-1) continue;
				if(i==len) res=max(res,dp[i][j][k]);
				else{
					rb(l,1,26){
						if(dp[i+1][l][k+(l!=(s[i+1]-'a'+1))]==-1||dp[i+1][l][k+(l!=(s[i+1]-'a'+1))]<dp[i][j][k]+c[j][l])
						dp[i+1][l][k+(l!=(s[i+1]-'a'+1))]=dp[i][j][k]+c[j][l];
					}
				}		
			}
		}
	}
//	cout<<dp[n-3]['o'-'a'+1][K-1]<<endl;
	cout<<res<<endl;
	return 0;
}
/*
winner 4
4
s e 7
o s 8
l o 13
o o 8

abcdef 1
5
a b -10
b c 5
c d 5
d e 5
e f 5
*/