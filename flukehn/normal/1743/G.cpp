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
const int M=33;
int fib[M];
void init(){
	fib[0]=fib[1]=1;
	for(int i=2;i<M;++i) fib[i]=fib[i-1]+fib[i-2];
}
int calc(int n,int i=M-1){
	while(n>2) {
		for(;;--i) if(fib[i-1]<n) break;
		n-=fib[i-1];//return calc(n-fib[i-1], i-2);
		i-=2;
	}
	return n==1?1:0;
}
int n;
struct P{
	int len;
	Int a;
};
void solve(){
	string s;
	vector<P> t;
	Int sum=1,lst=1;
	t.push_back((P){0, 1});
	for(int i=1;i<=n;++i){
		cin>>s;
		for(char c:s) {
			vector<P> nt;
			Int tmp=sum;
			for(auto p:t) {
				if(calc(p.len+1) == c-'0') {
					p.len++;
					nt.push_back(p);
					
				}
			}
			t.swap(nt);
			int pos=M-1;
			for(auto p:t) {
				while(fib[pos]>p.len) pos--;
				if(p.len==fib[pos]) tmp-=p.a;
			}
			if(c=='0') tmp-=lst;
			lst=tmp;
			sum+=tmp;
			//dbg(sum, lst, tmp);
			t.push_back((P){0, tmp});
		}
		cout<<lst<<"\n";
	}
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	cin.tie(0)->sync_with_stdio(0);
	init();
	while(cin>>n){
		solve();
	}
}