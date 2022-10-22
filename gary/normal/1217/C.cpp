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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int nex[200000+10];
int main(){
	int t;
	cin>>t;
	while(t--){
	memset(nex,0,sizeof(nex));
	string s;
	cin>>s;
	int len=s.length();
	nex[len]=INF;
	rl(i,len-1,0){
		nex[i]=nex[i+1];
		if(s[i]=='1') nex[i]=i;
	} 
	int res=0;
	rep(i,len){
		int is=1;
		if(nex[i]==INF) continue;
		int done=(nex[i]-i+1);
		if(is==done) res++;
		rb(j,nex[i]+1,len-1){
			is<<=1;
			done++;
			if(s[j]=='1') is++;
			if(is==done) res++;
			if(is>done) break;
//			cout<<is<<" "<<done<<endl;
		}
//		cout<<i<<" "<<res<<endl;
	}
	cout<<res<<endl;	
	}
	
	return 0;
}