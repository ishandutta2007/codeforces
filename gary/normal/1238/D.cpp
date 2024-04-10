//* AuThOr GaRyMr *//
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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	LL res=(LL)(n)*(n-1);
	res/=2;
	int cnt=0;
	rep(i,n){
		if(i){
			if(s[i]!=s[i-1]){
				res-=cnt;
				cnt=1;
			}
			else 
			cnt++;
		}
		else
		{
			cnt++;
		}
	}
	string tmp="";
	rl(i,n-1,0) tmp+=s[i];
	s=tmp;
//	cout<<s<<endl;
	cnt=0;
	rep(i,n){
		if(i){
			if(s[i]!=s[i-1]){
				res-=cnt-1;
				cnt=1;
			}
			else 
			cnt++;
		}
		else
		{
			cnt++;
		}
	}
	cout<<res<<endl;
	return 0;
}