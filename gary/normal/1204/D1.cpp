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
int dp[2000+10][2000+10][2];
int len;
string s;
string t;int OK[2000+10];
int sum1[2000+10],sum0[2000+10];
int main(){
	cin>>s;
	len=s.length(),s='$'+s;
	int has1,has0;
	has1=has0=0;
	rl(i,len,1){
		if(s[i]=='1') has1++;
		else has0++;
		if(has1>has0&&s[i]=='1'){
			s[i]='0';
			has0++;
		}
		
	}
	rb(i,1,len) cout<<s[i];
	return 0;
}