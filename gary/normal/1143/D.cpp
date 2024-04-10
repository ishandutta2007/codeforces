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
map<LL,int> ex;
LL gcd(LL A,LL B){
	if(B>A)swap(A,B);
	if(B==0) return A;
	return gcd(B,A%B);
}
int main(){
	LL n,k;
	cin>>n>>k;
	int a,b;
	cin>>a>>b;
	for(LL i=b+1;i<=n*k;i+=k){
		if(i>=a+1) ex[i-a-1]=1;
		if(i>=k+1-a) ex[i-(k+1-a)]=1;  
	}
	for(LL i=k+1-b;i<=n*k;i+=k){
		if(i>=a+1) ex[i-a-1]=1;
		if(i>=k+1-a) ex[i-(k+1-a)]=1;  
	}
	LL xres=10000000000000000,dres=-10000000000000000;
	for(map<LL,int> :: IT ite=ex.begin();ite!=ex.end();ite++){
		LL tmpl=(*ite).FIR;
		LL tmpres=n*k/gcd(tmpl,n*k);
		xres=min(xres,tmpres);
		dres=max(dres,tmpres);
	}
	cout<<xres<<" "<<dres<<endl;
	return 0;
}