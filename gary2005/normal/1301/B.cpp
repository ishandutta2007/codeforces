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
int a[100000+1];
void solve(){
	int n;
	cin>>n;
	rb(i,1,n) cin>>a[i];
	vector<int> v;
	int las=INF;
	rb(i,1,n){
		if(a[i]==-1){
			if(las==-1) continue;
			else v.PB(-1);
		}
		else{
			v.PB(a[i]);
		}
		las=a[i];
	}
//	for(auto it:each)
	int SZ=v.size();
	if(SZ==1){
		cout<<0<<" 1"<<endl;
	}
	else{
		int RR=-INF;
		int m,mm;
		m=-INF,mm=INF;
		int las=INF;
		for(auto it:v){
			if(las==INF){
				
			}
			else{
				if(las==-1){
					m=max(m,it);
					mm=min(mm,it);
				}
				else{
					if(it==-1){
						m=max(m,las);
						mm=min(mm,las);
					}
					else{
						RR=max(RR,abs(it-las));
					}
				}
			}
			las=it;
		}
		int K=(mm+m)/2;
		RR=max(RR,max(abs(K-mm),abs(K-m)));
		cout<<RR<<" "<<K<<endl;
	}
	
}
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}