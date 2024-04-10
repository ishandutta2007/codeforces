/*
AuThOr Gwj
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
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
#define biggest(A,B) A=max(A,B)
#define smallest(A,B) A=min(A,B)
#define get(a) cin>>a
#define get2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
char iv(char c){
	if(c=='0') return '1';
	return '0';
}
vector<int> res;void work(string s1,string s2,int p){
//	cout<<s1<<" "<<s2<<" "<<p<<endl;
	if(p==0) return;
	if(s1[p-1]==s2[p-1]){
		work(s1,s2,p-1);
	}
	else{
		if(p==1){
//			cout<<"!"<<endl;
			res.PB(1);
			return ;
		}
		if(s1[0]==s2[p-1]){
			s1[0]=iv(s1[0]);
			res.PB(1);
			rep(i,p)
				s1[i]=iv(s1[i]);
			rep(i,p){
				if((i+1)*2<=p){
					swap(s1[i],s1[p-1-i]);
				}
			}
			res.PB(p);
			work(s1,s2,p-1);
		}
		else{
			rep(i,p)
				s1[i]=iv(s1[i]);
			rep(i,p){
				if((i+1)*2<=p){
					swap(s1[i],s1[p-1-i]);
				}
			}
			res.PB(p);
			work(s1,s2,p-1);
		}
	}
}
void solve(){
res.clear();
int n;


string a,b;
	cin>>n;
	cin>>a>>b;
	work(a,b,b.length());
	cout<<res.size()<<" ";
	for(auto it:res){
		cout<<it<<" ";
	}
	cout<<endl;
}
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--) solve();	
	return 0;
}