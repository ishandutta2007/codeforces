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
map<int,int> have;
//int n,m;
int a[101],b[101];
int n,m;
int main(){
	cin>>n;
	rb(i,1,n) cin>>a[i];
	cin>>m;
	rb(i,1,m)cin>>b[i];
	sort(a+1,a+1+n),sort(b+1,b+1+m);
	cout<<a[n]<<" "<<b[m]<<endl;
	return 0;
}