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
int n; 
string black="black";
string query(int x){
	cout<<x<<" "<<1<<endl;
	ff;
	string tmp;
	cin>>tmp;
	return tmp; 
}
int main(){
	fastio;
	cin>>n;
	string start=query(0);
	int l=0,r=1e9+1;
	if(start=="black") black="white";
	int las1,las2;
	las1=0,las2=1e9;
	rb(i,1,n-1){
		int mid=(l+r)>>1;
		string tmp=query(mid);
//		cout<<tmp<<" "<<
		if(tmp==black){
			r=mid;
			las2=mid;
		}
		else{
			l=mid;
			las1=mid;
		}
	}
	cout<<las1<<" "<<0<<" "<<las2<<" "<<2<<endl;
	return 0;
}