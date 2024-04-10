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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL res=0;
LL totv=0;LL dp[1000000+10];
	LL dp2[1000000+10];
int main(){
	string s;
	cin>>s;
	
	int len=s.length();
	rb(i,0,len-1){
		if(i!=0)dp[i]=dp[i-1];
		if(s[i]=='o'){
			continue;
		}
		if(i!=0){
			if(s[i-1]!='o')
			dp[i]+=1;
		}
//		totv++;
	}
	totv=0;
	rl(i,len-1,0){
		dp2[i]=dp2[i+1];
		if(s[i]=='o'){
			continue;
		}
		if(i!=len-1){
			if(s[i+1]!='o')
			dp2[i]+=1;
		}
//		totv++;
	}
	rb(i,0,len-1){
		if(i!=0)if(s[i]=='o'){
			res+=dp[i-1]*dp2[i+1];
		}
	}
	cout<<res<<endl;
	return 0;
}