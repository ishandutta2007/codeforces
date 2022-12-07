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
int n,m;
int a[N];
const int M=20;
int t;
int p[M], k[M];
int q[M], v[M];
int wk(int x) {
	int th=m/x;
	//int y=x;
	int s=0;
	//dbg(x);
	for(int i=0;i<t;++i) {
		q[s]=i;
		v[s]=0;
		while(x%p[i]==0) x/=p[i], v[s]+=1;
		//dbg(q[s], v[s], p[i], k[i]);
		if(v[s] < k[i]) s++;
	}
	for(int i=0;i<s;++i) k[q[i]]=v[i];
	Int ans=0;
	for(int i=0;i<(1<<s);++i) {
		int tmp=th, f=1;
		for(int j=0;j<s;++j) if(i>>j&1) f=-f, tmp /= p[q[j]];
		ans += f * tmp;
		//dbg(i, f, tmp);
	}
	return ans.x;
}
int solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<n;++i) if(a[i]%a[i+1]) return 0;
	//b[1]=a[1]
	int x=a[1];
	t=0;
	for(int i=2;i*i<=x;++i){
		if(x%i==0){
			p[t]=i;
			k[t]=0;
			while(x%i==0) k[t]+=1, x/=i;
			t++;
		}
	}
	if(x>1){
		p[t]=x;
		k[t++]=1;
	}
	Int ans=1;
	for(int i=2;i<=n;++i) {
		dbg(i);
		ans *= wk(a[i]);
	}
	return ans.x;
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		cout << solve() << "\n";
	}
}