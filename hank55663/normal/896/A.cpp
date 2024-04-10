#include<bits/stdc++.h>

#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define INF 0x7fffffff
#define next Next
using namespace std;
typedef long long LL;
string s1="What are you doing at the end of the world? Are you busy? Will you save us?";
string s2="What are you doing while sending \"";
string s3="\"? Are you busy? Will you send \"";
string s4="\"?";
LL dp[100005];
char Find(int n,LL k){
	if(n==0)
	return s1[k-1];
	if(k<=s2.length())
	return s2[k-1];
	k-=s2.length();
	if(k<=dp[n-1])
	return Find(n-1,k);
	k-=dp[n-1];
	if(k<=s3.length())
	return s3[k-1];
	k-=s3.length();
	if(k<=dp[n-1])
	return Find(n-1,k);
	k-=dp[n-1];
	if(k<=s4.length())
	return s4[k-1];
	return '.'; 
}
int main(){
	dp[0]=s1.length();
	for(int i=1;i<=100000;i++){
		dp[i]=dp[i-1]*2+s2.length()+s3.length()+s4.length();
		if(dp[i]>1e18)
		dp[i]=1e18;
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int n;
		LL k;
		scanf("%d %I64d",&n,&k);
		if(dp[n]<k)
		printf(".");
		else
		printf("%c",Find(n,k));
	}
}