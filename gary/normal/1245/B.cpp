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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int _fixed[101],n;
string s;
int a,b,c;
int t; 
void solve(){
	cin>>n>>a>>b>>c;
	rb(i,1,n) _fixed[i]=0;
	int Win=0;
	int cntR=0,cntP=0,cntS=0;
	cin>>s;
	rep(i,n){
		if(s[i]=='R') cntR++;
		else if(s[i]=='P') cntP++;
		else cntS++; 
	}
	Win+=min(a,cntS);
	Win+=min(b,cntR);
	Win+=min(c,cntP);
//	cout<<Win<<endl;
	if(Win>=(n+1)/2)
	{
		puts("YES");
		rb(i,1,n)
		{
			if(a&&s[i-1]=='S'){
				a--;
				_fixed[i]=1;
			}
			if(b&&s[i-1]=='R'){
				b--;
				_fixed[i]=2;
			}
			if(c&&s[i-1]=='P')
			{
				c--;
				_fixed[i]=3;
			}
		}
		rb(i,1,n){
			if(!_fixed[i]){
				if(a){
					a--;
					_fixed[i]=1;
				}
				else
				if(b){
					b--;
					_fixed[i]=2;
				}
				else {
					c--;
					_fixed[i]=3;
				}
			}
		}
		rb(i,1,n){
			if(_fixed[i]==1){
				cout<<"R";
			}
			else
			if(_fixed[i]==2){
				cout<<"P";
			}
			else cout<<"S";
		}
		puts("");
	}
	else{
		puts("NO");
	}
}
int main(){
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}