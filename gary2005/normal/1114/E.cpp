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
int flag[1000000+1];
int main(){
	fastio;
	int n;
	cin>>n;
	if(n<=60){
		vector<int> v;
		rb(i,1,n){
			cout<<"? "<<i<<endl;ff;
			int a;
			cin>>a;
			v.PB(a);
		}
		sort(ALL(v));
		cout<<"! "<<v[0]<<" "<<v[1]-v[0]<<endl; 
		return 0;
	}
	int l=0,r=1000000000;
	while(l<r){
		int mid=(l+r)>>1;
		cout<<"> "<<mid<<endl;ff;
		bool b;
		cin>>b;
		if(b){
			l=mid+1; 
		}
		else{
			r=mid;
		}
	}
	int d;
	vector<int> v;
	SRAND;
	rb(i,1,30){
		int POS=random(n)+1;
		while(flag[POS]){
			POS=random(n)+1;
		}
		flag[POS]=1;
		cout<<"? "<<POS<<endl;ff;
		int a;
		cin>>a;
		v.PB(a);
	}
	sort(ALL(v));
	d=v[1]-v[0];
	rb(i,1,29){
		d=__gcd(d,v[i]-v[i-1]);
	}
	cout<<"! "<<l-(n-1)*d<<" "<<d<<endl;
	return 0;
}