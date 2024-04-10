#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL n;LL k;
LL dp[101][101];
string S;
LL last[101];
map<char , LL> FIRF;
LL res=0;
int JIAN(int i,int j){
	if(last[i]){
		return dp[last[i]-1][j-1];
	}
	else{
		return 0;
	}
}
void solve(){
	rb(i,0,100) {
		dp[i][0]=1;
	}
	rb(i,1,n){
		last[i]=FIRF[S[i-1]];
		FIRF[S[i-1]]=i;
	}
	rb(i,1,n){
		rb(j,1,n){
			dp[i][j]=dp[i-1][j]+dp[i-1][j-1]-JIAN(i,j);//cout<<dp[i][j]<<" ";
		}
		//cout<<endl;
	}
	LL tmpk=k;
	rl(i,n,0){
		if(tmpk<=0) break;
		res+=(LL)(min(tmpk,dp[n][i]))*(n-(LL)(i));
		tmpk-=dp[n][i];
	}
	if(tmpk>0){
		res=-1;
	}
}
int main(){
	scanf("%I64d %I64d",&n,&k);
	cin>>S;
	solve();
	printf("%I64d\n",res);
	return 0;
}