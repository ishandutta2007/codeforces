//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int height[55];
int main(){
	
	int n,m,h;
	cin>>n>>h>>m;
	rb(i,1,n) height[i]=h;
	rb(i,1,m){
		int li,ri,x;
		cin>>li>>ri>>x;
		rb(i,li,ri) height[i]=min(height[i],x);
	}
	int res=0;
	rb(i,1,n) res+=height[i]*height[i];
	cout<<res<<endl;
		return 0;
}