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
int main(){
	int t;
	cin>>t;
	while(t--){
		int len;
		cin>>len;
		string s;
		cin>>s;
		string rs=s;
		reverse(ALL(rs));
		if(s==rs){
			int cnt=0;
			rep(i,s.length()/2){
				cnt+=s[i]=='0';
			}
			if(s.length()&1){
				if(s[s.length()/2]=='0'){
					if(cnt) puts("ALICE");
					else puts("BOB");
				}
				else{
					puts("BOB");
				}
			}
			else{
				puts("BOB");
			}
		}
		else{
			int diff=0;
			rep(i,s.length()/2) diff+=s[i]=='0',diff+=rs[i]=='0';
			if(s.length()&1&&s[s.length()/2]=='0'&&diff==1){
				puts("DRAW");
			}
			else
			puts("ALICE");
		}
	}
	return 0;
}