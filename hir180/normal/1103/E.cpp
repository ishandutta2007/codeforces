#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define ull unsigned long long
#define B 10
struct poly{
	array<ull,B> ar;
	//ar[j]e^(2 * pi * i / 10 * j)
	poly(){
		ar.fill(0);
	}
	poly(ull x){
		ar.fill(0);
		ar[0] = x;
	}
	poly &operator+=(const poly &pp) {
        rep(i,B){
            ar[i] += pp.ar[i];
        }
        return *this;
	}
    poly &operator-=(const poly &pp) {
        rep(i,B){
            ar[i] -= pp.ar[i];
        }
        return *this;
    }

	poly operator* (const poly &pp) const{
		poly ret;
		rep(i,B){
			rep(j,B){
				ret.ar[(i+j)%B] += ar[i] * pp.ar[j];
			}
		}
		return ret;
	}
	poly modpow(int n) const {
		poly ret(1);
		poly mul = *this;
		while(n){
			if(n%2 == 1) ret = ret*mul;
			n /= 2;
			mul = mul*mul;
		}
		return ret;
	}
	poly shift(int x) const{
		poly ret;
		rep(i,B){
			ret.ar[(i+x)%B] =  ar[i];
		}
		return ret;
	}
	ull calc() const{
		//x = e^(2 * pi * i / 10)
		//x^10-1 = 0
		//(x^5-1)(x^5+1) = 0
		//x^5+1 = 0 (x^5 = -1)
		//(x+1)(x^4-x^3+x^2-x+1) = 0
		//x^4-x^3+x^2-x+1 = 0 <- cpy.ar[0]0
		poly cpy = *this;
		for(int i=0;i<5;i++){
			//x^5 = -1
			cpy.ar[i] -= cpy.ar[i+5];
		}
		ull w = cpy.ar[4];
		cpy.ar[4] -= w;
		cpy.ar[3] += w;
		cpy.ar[2] -= w;
		cpy.ar[1] += w;
		cpy.ar[0] -= w;
		return cpy.ar[0];
	}
};
const int mx = 100000;
poly num[mx + 10];

void DFT(int dif,bool rev){
	int dir = (rev?B-1:1);
	for(int beg=0;beg<mx;beg++){
		if(beg % (dif*10) >= dif) continue;
		//0
		int look[B];
		for(int i=0;i<B;i++) look[i] = beg + i * dif;
		poly tmp[B];
		for(int i=0;i<B;i++){
			for(int j=0;j<B;j++){
				tmp[i] += num[look[j]].shift((i*j*dir)%B);
			}
		}
		for(int i=0;i<B;i++){
			num[look[i]] = tmp[i];
		}
	}
}
array<ull,mx+10>ans;
int n;
int main(){
	//5DFT
	ios_base::sync_with_stdio(0);
  	cin.tie(0);
  	cin >> n;
  	rep(i,n){
  		int x; cin>>x; num[x].ar[0]++;
  	}
  	//DFT
  	for(int coef=1;coef<mx;coef*=10){
  		DFT(coef,false);
  	}
  	//N
    for(int i=0;i<mx;i++){
  		num[i] = num[i].modpow(n);
  	}
  	//inverse_DFT
  	for(int coef=1;coef<mx;coef*=10){
  		DFT(coef,true);
  	}
  	for(int i=0;i<n;i++){
  		ans[i] = num[i].calc();
  		//ans[i]10^5mod 2^64
  		//ans[i]32mod 2^645^5mod 2^58
  		assert(ans[i] % 32ULL == 0);
  		ans[i] /= 32ULL;
  		ull y = (1ull<<63) / 5;
  		ull x = y*2+1;
  		ull rev = x*4+1;
  		rep(j,5) ans[i] = ans[i]*rev;
  		ans[i] %= (1ull<<58);
  		cout<<ans[i]<<endl;
  	}
}