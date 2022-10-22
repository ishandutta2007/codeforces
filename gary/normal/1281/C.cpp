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
10.
11.
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
void solve(){
	int x;
	cin>>x;
	string s;
	cin>>s;
	s='%'+s;
	LL slen,tlen;
	slen=tlen=s.length()-1;
	rb(i,1,x){
		tlen--;
		LL tt=0;
		rb(j,1,s[i]-'0'-1){
			slen+=tlen;
			slen%=(LL)(1e9+7);
			tt+=tlen;
			tt%=(LL)(1e9+7);
			rb(k,1,tlen){
				if(s.length()<x+1){
					s+=s[i+k];
				}
				else
				break;
			}
		}
		tlen+=tt;
		tlen%=(LL)(1e9+7);
	}
	cout<<slen<<endl; 
} 
int main(){
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}