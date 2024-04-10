// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

using uint = unsigned int;
using ull = unsigned long long;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

template <uint MD> struct ModInt {
    using M = ModInt;
    const static M G;
    uint v;
    ModInt(ll _v = 0) { set_v(_v % MD + MD); }
    M& set_v(uint _v) {
        v = (_v < MD) ? _v : _v - MD;
        return *this;
    }
    explicit operator bool() const { return v != 0; }
    M operator-() const { return M() - *this; }
    M operator+(const M& r) const { return M().set_v(v + r.v); }
    M operator-(const M& r) const { return M().set_v(v + MD - r.v); }
    M operator*(const M& r) const { return M().set_v(ull(v) * r.v % MD); }
    M operator/(const M& r) const { return *this * r.inv(); }
    M& operator+=(const M& r) { return *this = *this + r; }
    M& operator-=(const M& r) { return *this = *this - r; }
    M& operator*=(const M& r) { return *this = *this * r; }
    M& operator/=(const M& r) { return *this = *this / r; }
    bool operator==(const M& r) const { return v == r.v; }
    M pow(ll n) const {
        M x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    M inv() const { return pow(MD - 2); }
    friend ostream& operator<<(ostream& os, const M& r) { return os << r.v; }
};
using Mint = ModInt<998244353>;
template <> const Mint Mint::G = Mint(3);

template <class Mint> void nft(bool type, V<Mint>& a) {
    int n = int(a.size()), s = 0;
    while ((1 << s) < n) s++;
    assert(1 << s == n);

    static V<Mint> ep, iep;
    while (int(ep.size()) <= s) {
        ep.push_back(Mint::G.pow(Mint(-1).v / (1 << ep.size())));
        iep.push_back(ep.back().inv());
    }
    V<Mint> b(n);
    for (int i = 1; i <= s; i++) {
        int w = 1 << (s - i);
        Mint base = type ? iep[i] : ep[i], now = 1;
        for (int y = 0; y < n / 2; y += w) {
            for (int x = 0; x < w; x++) {
                auto l = a[y << 1 | x];
                auto r = now * a[y << 1 | x | w];
                b[y | x] = l + r;
                b[y | x | n >> 1] = l - r;
            }
            now *= base;
        }
        swap(a, b);
    }
}

template <class Mint> V<Mint> multiply(const V<Mint>& a, const V<Mint>& b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};
    if (min(n, m) <= 8) {
        V<Mint> ans(n + m - 1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) ans[i + j] += a[i] * b[j];
        return ans;
    }
    int lg = 0;
    while ((1 << lg) < n + m - 1) lg++;
    int z = 1 << lg;
    auto a2 = a, b2 = b;
    a2.resize(z);
    b2.resize(z);
    nft(false, a2);
    nft(false, b2);
    for (int i = 0; i < z; i++) a2[i] *= b2[i];
    nft(true, a2);
    a2.resize(n + m - 1);
    Mint iz = Mint(z).inv();
    for (int i = 0; i < n + m - 1; i++) a2[i] *= iz;
    return a2;
}

template <class D> struct Poly {
    V<D> v;
    Poly(const V<D>& _v = {}) : v(_v) { shrink(); }
    void shrink() {
        while (v.size() && !v.back()) v.pop_back();
    }

    int size() const { return int(v.size()); }
    D freq(int p) const { return (p < size()) ? v[p] : D(0); }

    Poly operator+(const Poly& r) const {
        auto n = max(size(), r.size());
        V<D> res(n);
        for (int i = 0; i < n; i++) res[i] = freq(i) + r.freq(i);
        return res;
    }
    Poly operator-(const Poly& r) const {
        int n = max(size(), r.size());
        V<D> res(n);
        for (int i = 0; i < n; i++) res[i] = freq(i) - r.freq(i);
        return res;
    }
    Poly operator*(const Poly& r) const { return {multiply(v, r.v)}; }
    Poly operator*(const D& r) const {
        int n = size();
        V<D> res(n);
        for (int i = 0; i < n; i++) res[i] = v[i] * r;
        return res;
    }
    Poly operator/(const D& r) const { return *this * r.inv(); }
    Poly operator/(const Poly& r) const {
        if (size() < r.size()) return {{}};
        int n = size() - r.size() + 1;
        return (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);
    }
    Poly operator%(const Poly& r) const { return *this - *this / r * r; }
    Poly operator<<(int s) const {
        V<D> res(size() + s);
        for (int i = 0; i < size(); i++) res[i + s] = v[i];
        return res;
    }
    Poly operator>>(int s) const {
        if (size() <= s) return Poly();
        V<D> res(size() - s);
        for (int i = 0; i < size() - s; i++) res[i] = v[i + s];
        return res;
    }
    Poly& operator+=(const Poly& r) { return *this = *this + r; }
    Poly& operator-=(const Poly& r) { return *this = *this - r; }
    Poly& operator*=(const Poly& r) { return *this = *this * r; }
    Poly& operator*=(const D& r) { return *this = *this * r; }
    Poly& operator/=(const Poly& r) { return *this = *this / r; }
    Poly& operator/=(const D& r) { return *this = *this / r; }
    Poly& operator%=(const Poly& r) { return *this = *this % r; }
    Poly& operator<<=(const size_t& n) { return *this = *this << n; }
    Poly& operator>>=(const size_t& n) { return *this = *this >> n; }

    Poly pre(int le) const {
        return {{v.begin(), v.begin() + min(size(), le)}};
    }
    Poly rev(int n = -1) const {
        V<D> res = v;
        if (n != -1) res.resize(n);
        reverse(res.begin(), res.end());
        return res;
    }
    Poly diff() const {
        V<D> res(max(0, size() - 1));
        for (int i = 1; i < size(); i++) res[i - 1] = freq(i) * i;
        return res;
    }
    Poly inte() const {
        V<D> res(size() + 1);
        for (int i = 0; i < size(); i++) res[i + 1] = freq(i) / (i + 1);
        return res;
    }

    // f * f.inv() = 1 + g(x)x^m
    Poly inv(int m) const {
        Poly res = Poly({D(1) / freq(0)});
        for (int i = 1; i < m; i *= 2) {
            res = (res * D(2) - res * res * pre(2 * i)).pre(2 * i);
        }
        return res.pre(m);
    }
    Poly exp(int n) const {
        assert(freq(0) == 0);
        Poly f({1}), g({1});
        for (int i = 1; i < n; i *= 2) {
            g = (g * 2 - f * g * g).pre(i);
            Poly q = diff().pre(i - 1);
            Poly w = (q + g * (f.diff() - f * q)).pre(2 * i - 1);
            f = (f + f * (*this - w.inte()).pre(2 * i)).pre(2 * i);
        }
        return f.pre(n);
    }
    Poly log(int n) const {
        assert(freq(0) == 1);
        auto f = pre(n);
        return (f.diff() * f.inv(n - 1)).pre(n - 1).inte();
    }
    Poly sqrt(int n) const {
        assert(freq(0) == 1);
        Poly f = pre(n + 1);
        Poly g({1});
        for (int i = 1; i < n; i *= 2) {
            g = (g + f.pre(2 * i) * g.inv(2 * i)) / 2;
        }
        return g.pre(n + 1);
    }

    Poly pow_mod(ll n, const Poly& mod) {
        Poly x = *this, r = {{1}};
        while (n) {
            if (n & 1) r = r * x % mod;
            x = x * x % mod;
            n >>= 1;
        }
        return r;
    }

    friend ostream& operator<<(ostream& os, const Poly& p) {
        if (p.size() == 0) return os << "0";
        for (auto i = 0; i < p.size(); i++) {
            if (p.v[i]) {
                os << p.v[i] << "x^" << i;
                if (i != p.size() - 1) os << "+";
            }
        }
        return os;
    }
};

Mint fac[1000005];
Mint ifac[1000005];
Mint invn[1000005];

Mint nCk(int i,int j){
	return fac[i]*ifac[i-j]*ifac[j];
}

vector<Mint> eval(Poly<Mint> p,vector<Mint> X){
	int sz=sz(X);
	while (__builtin_popcount(sz(X))>1) X.pub(0);
	
	int layer=__builtin_ctz(sz(X));
	vector<Poly<Mint> > v[layer];
	rep(x,0,sz(X)) v[0].pub(Poly<Mint>({-X[x],1}));
	rep(x,0,layer-1) for (int y=0;y<sz(v[x]);y+=2){
		v[x+1].pub(v[x][y]*v[x][y+1]);
	}
	
	vector<Poly<Mint> > res[layer+1];
	res[layer]={p};
	rep(x,layer,0) rep(y,0,sz(res[x+1])){
		res[x].pub(res[x+1][y]%v[x][y<<1]);
		res[x].pub(res[x+1][y]%v[x][y<<1|1]);
	}
	
	vector<Mint> ans;
	rep(x,0,sz) ans.pub(res[0][x].freq(0));
	return ans;
}

pair<Poly<Mint>,Poly<Mint> > __solve(vector<Mint> X,vector<Mint> Y){
	if (sz(X)==1){
		return {Poly<Mint>({Y[0]}),Poly<Mint>({-X[0],1})};
	}
	else{
		int h=sz(X)>>1;
		
		vector<Mint> X0,X1;
		vector<Mint> Y0,Y1;
		
		rep(x,0,sz(X)){
			if (x<h) X0.pub(X[x]),Y0.pub(Y[x]);
			else X1.pub(X[x]),Y1.pub(Y[x]);
		}
		
		auto res1=__solve(X0,Y0),res2=__solve(X1,Y1);
		return {res1.fi*res2.se+res1.se*res2.fi,res1.se*res2.se};
	}
} 

Poly<Mint> inter(vector<Mint> X,vector<Mint> Y){
	deque<Poly<Mint> > dq;
	for (auto it:X) dq.pub(Poly<Mint>({-it,1}));
	while (sz(dq)>1){
		dq.pub(dq[0]*dq[1]);
		dq.pof(),dq.pof();
	}
	
	auto div=eval(dq[0].diff(),X);
	rep(x,0,sz(Y)) Y[x]/=div[x];
	
	return __solve(X,Y).fi;
}

int n,k,p;
int arr[100005];
Mint val[100005];
Mint calc[100005];

vector<Mint> tup[100005];

vector<vector<Mint>> v[100005];
vector<Mint> merge(vector<Mint> a,vector<Mint> b){
	return {
		a[0]*b[3]+a[1]*b[2]+a[2]*b[1]+a[3]*b[0],
		a[1]*b[3]+a[3]*b[1],
		a[2]*b[3]+a[3]*b[2],
		a[3]*b[3]
	};
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x;
	ifac[1000004]=fac[1000004].inv();
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x;
	rep(x,1,1000005) invn[x]=fac[x-1]*ifac[x];
	
	cin>>n>>k>>p;
	rep(x,1,n+1) cin>>arr[x];
	
	rep(x,1,k+2) calc[x]=calc[x-1]+Mint(p).pow(x)*Mint(x).pow(k);
	
	Mint num=0,denom=0;
	rep(x,0,k+2){
		Mint temp=Mint(-1).pow(x)*nCk(k+1,x);
		num+=temp*calc[x]/Mint(p).pow(x+1);
		denom+=temp/Mint(p).pow(x+1);
	}
	
	Mint c=num/denom;
	
	rep(x,0,k+2) calc[x]=(calc[x]-c)/Mint(p).pow(x+1);
	
	vector<Mint> X,Y;
	rep(x,0,k+2) X.pub(x),Y.pub(calc[x]);
	
	auto res=eval(inter(X,Y),vector<Mint>(arr,arr+n+1));
	rep(x,1,n+1) val[x]=res[x]*Mint(p).pow(arr[x]+1)+c;
	
	vector<Mint> temp={0,0,0,0};
	Mint ans=0;
	
	rep(x,1,n+1){
		temp[3]+=1;
		temp=merge(temp,{val[x],val[x],arr[x],arr[x]+1});
		ans+=temp[0];
	}
	
	cout<<ans<<endl;
}