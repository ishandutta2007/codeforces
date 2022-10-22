//* AuThOr GaRyMr *//
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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL f[200000+10],x[200000+10],n,m;
vector<int> each[200000+10]; 
int main(){
	cin>>n>>m;
	rb(i,1,m) cin>>x[i];
	rb(i,1,m-1){
		if(x[i]==x[i+1]) continue;
		int OK=0;
		if(x[i]>x[i+1]) {
			OK=1;
			swap(x[i],x[i+1]);
		}
		int one=abs(x[i]+1-x[i+1]);
		f[x[i]+1]+=one;
		f[x[i+1]]-=one;
		one=abs(x[i]-x[i+1]);
		f[1]+=one;
		f[x[i]]-=one;
		f[x[i+1]+1]+=one;
		f[n+1]-=one;
		if(OK) swap(x[i],x[i+1]);
		if(x[i]+1<=x[i+1]){
			f[x[i]]+=abs(x[i+1]-1);
			f[x[i]+1]-=abs(x[i+1]-1);
		}
		else{
			f[x[i]]+=x[i+1];
			f[x[i]+1]-=x[i+1]; 
		}
		swap(x[i],x[i+1]);
		if(x[i]+1<=x[i+1]){
			f[x[i]]+=abs(x[i+1]-1);
			f[x[i]+1]-=abs(x[i+1]-1);
		}
		else{
			f[x[i]]+=x[i+1];
			f[x[i]+1]-=x[i+1]; 
		}
		swap(x[i],x[i+1]);
	} 
	rb(i,1,n)
	{
		f[i]+=f[i-1];
		cout<<f[i]<<" ";
	}
	return 0;
}