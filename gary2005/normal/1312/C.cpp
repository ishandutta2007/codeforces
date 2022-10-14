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
int n,k;
LL a[33];
void solve(){
	map<int,int> used;
	cin>>n>>k;
	rb(i,1,n)
		cin>>a[i];
	bool ok=1;
	rb(i,1,n){
		if(ok==0) break;
		int tmp=1;
		while(a[i]){
			if(a[i]%k>1){
				ok=0;
				break;
			}
			if(a[i]%k){
				if(used[tmp]){
					ok=0;
					break;
				}
				used[tmp]=1;
			}
			tmp++;
			a[i]/=k;
		}
	}
	if(ok){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
}
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--) solve();	
	return 0;
}