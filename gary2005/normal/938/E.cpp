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
typedef pair<mp,mp> superpair;bool cmp(int A,int B){
	return A>B;
}
int bigger[1000000+1],smaller[1000000+1];
const int MOD=1e9+7;
LL res=0,fact[1000000+2],P[1000000+2];
LL  my_pow(LL A,LL B){
	if(B==0) return 1;
	LL tmp=my_pow(A,B>>1);
	tmp*=tmp;
	tmp%=MOD;
	if(B&1) tmp*=A;
	return tmp%MOD;
}
LL inv(LL x){return my_pow(x,MOD-2);}
LL p(int A,int B){
	return fact[B]*inv(fact[B-A])%MOD;
}
int main(){
	int n;
	vector<int> a;
	cin>>n;
	fact[0]=1;
	rb(i,1,1000000)
		fact[i]=fact[i-1]*i,fact[i]%=MOD;
	rb(i,1,n)
	{
		int tmp;
		cin>>tmp;
		a.PB(tmp);
	}
	int tmp=0;
	sort(ALL(a),cmp);
	rep(i,n){
		bigger[i]=tmp;
		if(i!=n-1){ 
			if(a[i]!=a[i+1]) tmp++;
		}
	}
	tmp=0;
	int cur=0;
	rl(i,n-1,0){
		cur++;
		smaller[i]=tmp;
		if(i!=0){
			if(a[i]!=a[i-1]) {
				tmp+=cur;
				cur=0;
			}
		}
	}
	LL res=0;
	rep(i,n){
		if(bigger[i]){
			res+=a[i]*fact[n]%MOD*inv(n-smaller[i])%MOD;
			res%=MOD;	
		}
	}
	cout<<res<<endl;
	return 0;
}