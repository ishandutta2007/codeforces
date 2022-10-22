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
int ok[3][100000+4],res=0; 
int main(){
	fastio;
	int n,k;
	cin>>n>>k;
	rb(i,1,k){
		int a,b;
		cin>>a>>b;
		ok[a][b]^=1;
		if(ok[a][b]){
		if(a==1){
			if(ok[a+1][b]) res++;
			if(ok[a+1][b-1]) res++;
			if(ok[a+1][b+1]) res++;
		}
		else{
			if(ok[a-1][b]) res++;
			if(ok[a-1][b-1]) res++;
			if(ok[a-1][b+1]) res++;
		}	
		}
		else{
			if(a==1){
			if(ok[a+1][b]) res--;
			if(ok[a+1][b-1]) res--;
			if(ok[a+1][b+1]) res--;
			}
			else{
			if(ok[a-1][b]) res--;
			if(ok[a-1][b-1]) res--;
			if(ok[a-1][b+1]) res--;
			}
		}
//		cout<<res<<endl;
		if(res==0)
		cout<<"Yes\n";
		else{
			cout<<"No\n";
		}
	}
	return 0;
}