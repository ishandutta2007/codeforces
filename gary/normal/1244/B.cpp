/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int calc(string s){
	int l=s.length();
	int res=l;
	rep(i,l){
		res+=s[i]-'0';
	}
//	cout<<s<<endl;
	rl(i,l-1,0){
		if(s[i]=='1'){
//			cout<<i<<" "<<endl;
			i++;
			res=max(res,i+i);
//			return;
			break;
		}
	}
	return res;
}
void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int cnt=0;
	rep(i,n){
		cnt+=s[i]-'0';
	}
	if(cnt==0){
		cout<<n<<endl;
		return;
	}
	int ans=calc(s);
	string tmp=s;
	s="";
	rl(i,n-1,0) s+=tmp[i];	//cout<<s<<endl;
	ans=max(ans,calc(s));
	cout<<ans<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}