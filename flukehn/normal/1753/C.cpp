#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int mo=998244353;
struct Int{
	int x;
	Int()=default;
	Int& operator=(int y){x=y%mo;if(x<0)x+=mo;return *this;}
	Int(int x){*this=x;}
	Int& operator*=(Int t){x=1LL*x*t.x%mo;return *this;}
	Int& operator+=(Int t){x=x+t.x>=mo?x+t.x-mo:x+t.x;return *this;}
	Int& operator-=(Int t){x=x-t.x<0?x-t.x+mo:x-t.x;return *this;}
	Int Pow(int b)const{Int a=*this,r(1);for(;b;b>>=1,a*=a)if(b&1)r*=a;return r;}
	Int Inv()const{return this->Pow(mo-2);}
	Int& operator/=(Int t){x=1LL*x*t.Inv().x%mo;return *this;}
	friend Int operator+(Int a,Int b){return a+=b;}
	friend Int operator-(Int a,Int b){return a-=b;}
	friend Int operator*(Int a,Int b){return a*=b;}
	friend Int operator/(Int a,Int b){return a/=b;}
	Int operator-()const{return x?(Int){mo-x}:(Int){0};}
    explicit operator int(){return x;}
	bool operator!() const { return x==0; }
};
std::ostream &operator<<(std::ostream &os, Int a){return os << (int)a;}
const int N=2e5+11;
int a[N];
int n,f[N];
int inv[N];
void init(){
	inv[1]=1;
	for(int i=2;i<N;++i) inv[i]=1LL*(mo-mo/i)*inv[mo%i]%mo;
}
int solve(){
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	int s=0;
	for(int i=1;i<=n;++i) s+=a[i];
	s=n-s;
	int t=0;
	for(int i=1;i<=s;++i) t+=a[i];
	Int ans=0;
	for(int i=t;i>=1;--i)
		ans += Int(inv[i]) * inv[i];
	dbg(ans);
	ans *= 1LL*(n-1)*n/2%mo;
	return (int)ans;
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	init();
	int t;
	cin>>t;
	while(t--){
		cout<<solve()<<"\n";
	}
}