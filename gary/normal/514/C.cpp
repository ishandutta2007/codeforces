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
8. CSPday2 meal
9.-or
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
#define POB pop_back
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int MOD=1e9+7,mar=998244353,MOD2=1e9+9,mar2=998244389;
map<pair<LL,int>,int> M,M2;
void record(string s){
	int len=s.length();
	LL tmp=0;
	LL tmp2=0;
	rep(i,len)
	{
		tmp*=mar;
		tmp+=s[i]-'a'+1;
		tmp%=MOD;
		tmp2*=mar2;
		tmp2+=s[i]-'a'+1;
		tmp2%=MOD2;
	}
	M[II(tmp,len)]=1;
	M2[II(tmp2,len)]=1;
}
bool check(string s){
	int len=s.length();
	LL tmp=0,tmp2=0;
	rep(i,len){
		tmp*=mar;
		tmp+=s[i]-'a'+1;
		tmp%=MOD;
		tmp2*=mar2;
		tmp2+=s[i]-'a'+1;
		tmp2%=MOD2;
	}
	LL mi=1,mi2=1;
	rl(i,len-1,0){
		if(s[i]=='a'){
			if((M[II((tmp+mi)%MOD,len)]&&M2[II((tmp2+mi2)%MOD2,len)])||(M[II((tmp+mi+mi)%MOD,len)]&&M2[II((tmp2+mi2+mi2)%MOD2,len)])){
				return 1;
			}
		}
		else{
			if(s[i]=='b'){
				if((M[II((tmp+mi)%MOD,len)]&&M2[II((tmp2+mi2)%MOD2,len)])||(M[II((tmp-mi+MOD)%MOD,len)]&&M2[II((tmp2-mi2+MOD2)%MOD2,len)])){
				return 1;
				}
			}
			else{
				if((M[II((tmp-mi+MOD)%MOD,len)]&&M2[II((tmp2-mi2+MOD2)%MOD2,len)])||(M[II((tmp-mi-mi+MOD*2)%MOD,len)]&&M2[II((tmp2-mi2-mi2+MOD2*2)%MOD2,len)])){
				return 1;
				}
			}
		}
		mi*=mar;
		mi%=MOD;
		mi2*=mar2;
		mi2%=MOD2;
	} 
	return 0;
}
int main(){
	int n,m;
	cin>>n>>m;
	string s;
	rb(i,1,n) cin>>s,record(s);
	rb(i,1,m){
		cin>>s;
		cout<<(check(s)? "YES":"NO")<<endl;
	}
	return 0;
}