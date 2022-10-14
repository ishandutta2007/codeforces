/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n;
int a[200000+20];
bool check(string s){
	int cnt=0;
	rep(i,n){
		if(s[i]=='('){
			cnt++;
		}
		else{
			if(!cnt) return 0;
			cnt--;
		}
	}
	return 1;
}
void solve(){
	scanf("%d",&n);
	int cnt=0;
	rb(i,1,n){
		char c;
		cin>>c;
		a[i]=c^48;
		cnt+=!a[i];
	}
	string s;
	if(cnt&1||!a[1]||!a[n]){
		cout<<"NO"<<endl;
		return ;
	}
	s.PB('(');
	int c1=0,c2=0;
	rb(i,2,n-1){
		if(a[i]==0){
			if(c1==0){
				s.PB('(');
			}
			else{
				s.PB(')');
			}
			c1^=1;
		}
		else{
			if(c2==0){
				s.PB('(');
			}
			else{
				s.PB(')');
			}
			c2^=1;
		}
	}
	s.PB(')');
	string s2;
	rb(i,1,n){
		if(a[i]==1){
			s2.PB(s[i-1]);
		}
		else{
			if(s[i-1]=='(') s2.PB(')');
			else s2.PB('(');
		}
	}
	cout<<"YES"<<endl<<s<<endl<<s2<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}