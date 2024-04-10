/*
AuThOr GaRyMr
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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
string s[104];
int order[104];
map<string,int> have;
int las=-1;
int main(){
	fastio;
	int n,m;
	cin>>n>>m;
	rb(i,1,n)
		cin>>s[i];
	rb(i,1,n)
	{
		have[s[i]]=i;
	}
	int ok=0;
	int a,b;
	a=0,b=n+1;
	rb(i,1,n){
		if(order[i]) continue;
		reverse(ALL(s[i]));
		if(!have[s[i]]){
			las=i;
		}
		else{
			if(ok&&have[s[i]]==i){
				
			}
			else{
			
			order[i]=++a;
			if(have[s[i]]!=i){
				
			order[have[s[i]]]=--b;	
				
			}
			else{
				ok=i;
			}
			}
			
		}
		reverse(ALL(s[i]));
	}
	string res="";
	rb(i,1,a){
		rb(j,1,n){
			if(ok!=j)
			if(order[j]==i) res=res+s[j];
		}
	}
	if(ok){
		res=res+s[ok];
	}
	rb(i,b,n){
		rb(j,1,n){if(ok!=j)
			if(order[j]==i) res=res+s[j];
		}
	}
	cout<<res.length()<<endl<<res<<endl;
	return 0;
}