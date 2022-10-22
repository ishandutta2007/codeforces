/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
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
int len,res=0,res1=1,res2=1;
string s,save;
int check(){
	int dp[505],cnt=0,mini=INF;
	rb(i,1,len){
		dp[i]=dp[i-1];
		if(s[i-1]=='('){
			dp[i]++;
		}
		else{
			dp[i]--;
		}
	}
	rb(i,1,len){
		if(dp[i]<mini)
		{
			cnt=0;
			mini=dp[i];
		}
		if(dp[i]==mini) cnt++;
	}
	return cnt;
}
int main(){
	cin>>len>>s;
	int cnt1,cnt2;
	cnt1=cnt2=0;
	rep(i,len){
		if(s[i]=='(') cnt1++;
		else cnt2++; 
	}
	if(cnt1!=cnt2){
		printf("0\n1 1");
		return 0;
	}
	save=s;
	rb(i,1,len)
		rb(j,1,len){
			s=save;
			swap(s[i-1],s[j-1]);
			int tmp=check();	
			if(tmp>res){
				res=tmp,res1=i,res2=j;
			}
		}
	cout<<res<<endl<<res1<<" "<<res2<<endl;
	return 0;
}