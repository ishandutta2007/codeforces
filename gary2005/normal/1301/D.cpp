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
vector<pair<int,string> > v;
int n,m,k;
int main(){
	fastio;
	
	cin>>n>>m>>k;
	if(4*n*m-2*n-2*m<k){
		cout<<"NO";
		return 0;
	}
	cout<<"YES"<<endl;
	if(n==1)
	{
//		cout<<1<<endl;
		if(k<=m-1){
			cout<<1<<endl;
			cout<<k<<" R";
		}
		else{
			cout<<2<<endl;
			cout<<m-1<<" R"<<endl;
			cout<<k-(m-1)<<" L"<<endl;
		}
		return 0;
	}
	if(m==1){
//		cout<<1<<endl;
		if(k<=n-1){
			cout<<1<<endl;
			cout<<k<<" D";
		}
		else{
			cout<<2<<endl;
			cout<<n-1<<" D"<<endl;
			cout<<k-(n-1)<<" U"<<endl;
		}
		return 0;
	}
//	if(m!=1)
	v.PB(II(1,"R"));
	rb(i,1,m-1){
		v.PB(II(n-1,"D"));
		v.PB(II(n-1,"U"));
		if(i+1!=m)
		v.PB(II(1,"R"));
	}
//	if(m!=1)
	v.PB(II(m-1,"L"));
	rb(i,1,n-1){
		v.PB(II(1,"D"));
		v.PB(II(m-1,"R"));
		v.PB(II(m-1,"L"));
	}
	v.PB(II(n-1,"U"));
	vector<pair<int,string>> final;
	for(auto it:v){
		if(k==0) break;
		if(it.FIR>k){
			final.PB(II(k,it.SEC));
//			cout<<k<<" "<<it.SEC<<endl;
			k=0;
		}
		else{
			final.PB(it);
//			cout<<it.FIR<<" "<<it.SEC<<endl;
			k-=it.FIR; 
		}
	}
	cout<<final.size()<<endl;
	for(auto it:final){
		cout<<it.FIR<<" "<<it.SEC<<endl;
	}
	return 0;
}