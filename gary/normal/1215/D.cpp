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
	string s;
	int len;
	cin>>len>>s;
	int sum1,sum2,tot1,tot2;
	sum1=sum2=tot1=tot2=0;
	rep(i,len>>1) {
		if(s[i]!='?') sum1+=s[i]-'0';
		else tot1++;
	}
	rep(i,len>>1) {
		if(s[i+(len>>1)]!='?') sum2+=s[i+(len>>1)]-'0';
		else tot2++;
	}
	if(sum1>sum2) {
		swap(sum1,sum2),swap(tot1,tot2);
	}
	int win=0;
	if(sum1==sum2){
//		cout<<tot1<<" "<<tot2<<endl;
		if(tot1!=tot2) win=1;
	}
	else{
		win=1;
		if(tot2>=tot1);
		else if(sum2-sum1==(tot1-tot2)/2*9) win=0;
	}
	cout<<(win? "Monocarp":"Bicarp");
	return 0;	
}