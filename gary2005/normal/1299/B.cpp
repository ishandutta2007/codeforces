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
typedef pair<double,double> mp;
typedef pair<mp,mp> superpair;
mp dd[100000+1];

int main(){
	fastio;
	int n;
	cin>>n;
	if(n&1){
		cout<<"No";
		return 0;
	}
	rb(i,1,n){
		cin>>dd[i].FIR>>dd[i].SEC;
	}
	sort(dd+1,dd+1+n);
	double x,y;
	x=(dd[1].FIR+dd[n].FIR)/2.0;
	y=(dd[1].SEC+dd[n].SEC)/2.0;
	rb(i,1,n/2){
		if((dd[i].FIR+dd[n-i+1].FIR)/2.0!=x||(dd[i].SEC+dd[n-i+1].SEC)/2.0!=y){
			cout<<"No";
			return 0;
		}
	} 
	cout<<"Yes";
	return 0;
}