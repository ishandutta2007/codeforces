/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
6.long double | 
7.!(prince and princess)
8. CSPday2 meal
9.-or
10.
11.
*/
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
#define POB pop_back
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n;int k;int m,h[200000+10];
LL fact[200000+10];
const int p= 998244353;
LL my_pow(LL x,LL mi){
	if(!mi) return 1ll;
	LL tmp=my_pow(x,mi>>1);
	tmp*=tmp;
	tmp%=p;
	if(mi&1) tmp*=x;
	return tmp%p; 
}
LL inv(LL x){
	return my_pow(x,p-2);
}
LL c(int M,int N){
	return ((fact[N]%p*inv(fact[N-M]))%p*inv(fact[M]))%p;
}
int f(){
	LL res=0;
	rb(i,1,n){
		res+=((c(i,n)%p*my_pow(2,i-1)%p-((i&1)? 0:c(i>>1,n)%p*c(i>>1,n-(i>>1))%p*inv(2)%p)+p)%p)*my_pow(k-2,n-i);
		res%=p;
//		cout<<res<<" "<<fact[n-i]<<" "<<my_pow(2,i-1)%p<<" "<<((c(i,n)%p*my_pow(2,i-1)%p-((i&1)? 0:c(i>>1,n)%p*c(i>>1,n-(i>>1))%p*inv(2)%p)+p)%p)<<endl;
	}
	res*=my_pow(k,m-n);
	res%=p;
	return (res);
}
int main(){	
	fact[0]=1ll;
	rb(i,1,200000) {
		fact[i]=fact[i-1]*i;fact[i]%=p;
//		if(fact[i]<0) cout<<i<<endl;
	}
	cin>>m>>k;
	rb(i,1,m) scanf("%d",&h[i]);
	h[m+1]=h[1]; 
	rb(i,1,m) if(h[i]!=h[i+1]) n++;
	 
	cout<<f();
	return 0;
}