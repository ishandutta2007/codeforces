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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
string s,t;
int len1,len2;
int dp[200000+10],dp2[200000+10];
int main(){
	cin>>s>>t;
	len1=s.length(),len2=t.length();
	s='$'+s;
	t='$'+t;
	rb(i,1,len1){
		dp[i]=dp[i-1];
		if(dp[i]<len2)
		if(s[i]==t[dp[i]+1]) dp[i]++;
	}
	rl(i,len1,1){
		dp2[i]=dp2[i+1];
		if(s[i]==t[len2-(dp2[i]+1)+1]) dp2[i]++;
	}
//	rb(i,1,len1) cout<<dp2[i]<<" ";
//	cout<<endl;
	int ite=1;
	int ite2=1;
	int res=-INF;
	rb(i,0,len2){
		while(dp[ite]<i) ite++;
		if(i==len2){
//			cout<<len1<<" "<<ite<<endl;
			res=max(res,len1-ite);
			break;
		}
		while(dp2[ite2]>=len2-i) ite2++;
//		cout<<dp2[ite2]<<endl;
//		cout<<"*"<<ite2<<endl;
		ite2--;
		if(i==0){
//			cout<<i.te2<<endl;
			res=max(res,ite2-1);
			continue;
		}
//		cout<<ite<<" "<<ite2<<endl;
		res=max(res,ite2-ite-1);
	}
	cout<<res<<endl;
	return 0;
}