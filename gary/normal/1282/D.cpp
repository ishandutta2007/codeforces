/*
AuThOr GaRyMr
IDEA:
	 ask :a?  b?
	n=min(ans1+1,ans2+1)
	ask: "bbbbbb"(nb)
	tota=ans,totb=n-tota;
	a
	 
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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
vector<int> v;
int main(){
	int tota,totb,n;
	cout<<string(300,'a')<<endl;
	ff;
	cin>>tota;
	if(!tota){
		return 0;
	}
	tota=300-tota;
	cout<<string(300,'b')<<endl;
	ff;
	cin>>totb;
	if(!totb){
		return 0;
	}
	totb=300-totb;
	n=tota+totb;
	string res="";
	int ok=0,len=0;
	rb(i,0,totb-1){
		if(ok==tota){
			res+='b';
			continue;
		}
		string ancient=res;
		res+='a';
		ok++;
		len++;
		cout<<res;
		rb(j,i+1,totb){
			cout<<'b';
		}
		puts("");
		ff;
		int tmp;
		cin>>tmp;
		if(tmp==0){
			return 0;
		}
		if(tmp==n-totb-ok){
//			cout<<'!'<<endl;
			i--;
		}
		else{
			res=ancient;
			res+='b';
			ok--;
			continue;
		}
	}
	rb(i,ok+1,tota){
		res+='a';
	}
	cout<<res<<endl;ff;
	int LALALL;
	cin>>LALALL;
	return 0;
}