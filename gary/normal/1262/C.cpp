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
int t,n,k;
string s1,s2;
char c1[2001],c2[2001];
void solve(){
	cin>>n>>k;
	cin>>s1;
	s2="";
	int tot=n/2;
	rb(i,1,k-1){
		s2+='(';
		s2+=')';
	}
	rb(i,k,tot){
		s2+='(';
	}
	rb(i,k,tot){
		s2+=')';
	}
	//cout<<s2<<endl;
	s2='&'+s2;
	s1='&'+s1;
	rb(i,1,n) c1[i]=s2[i];
	rb(i,1,n) c2[i]=s1[i];
	vector<mp> v;
	rb(i,1,n){
		if(c1[i]!=c2[i])
		rb(j,i,n){
			if(c2[j]==c1[i]){
				v.PB(II(i,j));
				reverse(c2+i,c2+j+1);
				break;
			}
		}
	}
	cout<<v.size()<<endl;
	for(auto it:v){
		cout<<it.FIR<<" "<<it.SEC<<endl;
	}
}
int main(){
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}