/*
{

AuThOr Gwj
*/
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rb(a,b,c) for(LL a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
LL exGcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0)
    {
        x = 1;
        y = 0;
        return a;
    }
    LL r = exGcd(b,a%b,x,y);
    LL t = x; x = y;
    y = t-a/b*y;
    return r;
}
LL quick(LL A,LL B,LL MOD){
	if(!B) return 0ll;
	LL tmp=quick(A,B>>1,MOD);
	tmp+=tmp;
	tmp%=MOD;
	if(B&1){
		tmp+=A;
		tmp%=MOD;
	}
	return tmp;
}
LL n,m;
LL a[10000+2];
int main(){
	fastio;
	R2(n,m);
	int k;
	R(k);
	LL i_=1,j_=1;
	rb(i,1,k){
		R(a[i]);
		LL tmp=a[i]/__gcd(i_,a[i]);
		if(tmp>(n+i_-1)/i_){ 
			cout<<"NO"<<endl;
			return 0;
		}
		LL M=i_;
		i_=tmp*i_;
		if(i_>n){
			cout<<"NO"<<endl;
			return 0;
		}
		if(i==1){
			j_=0;
		}
		else{
			/*
			j_+=M*t
			j_ +M*t== 1-i  (MOD a[i])
			a[i]*hi = j_+i-1+M*t 
			*/
			if((j_+i-1)%__gcd(M,a[i]))
			{	
				cout<<"NO";
				return 0;
			}
			LL t,hi;
			LL gg=(j_+i-1)/__gcd(M,a[i]);
			exGcd(M,a[i],t,hi);
			t*=-1;
			t%=a[i];
			if(t<0){
				t+=a[i];
			}
//			cout<<gg<<endl;
			gg%=i_;
			t=quick(t,gg,i_);
			j_+=quick(M,t,i_); 
			j_%=i_;
		}
//		cout<<i<<" "<<j_<<endl;
	}
	if(!j_) j_=i_;
	if(j_+k-1>m){
		cout<<"NO"<<endl;
		return 0;
	}
//	cout<<i_<<endl;
	rb(j,j_,j_+k-1){
//		cout<<__gcd(i_,(LL)j)<<endl;
		if(__gcd(i_,j)==a[j-j_+1]){
			
		}
		else{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}