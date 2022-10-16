#include<bits/stdc++.h>
using namespace std;
template<class T, T Q=2> constexpr T inf = numeric_limits<T>::max() / Q - 1;
template<class T,class S=T>inline bool umin(T&m,S&&x){return x<m?m=x,1:0;}
template<class T,class S=T>inline bool umax(T&m,S&&x){return m<x?m=x,1:0;}
auto operator<<(ostream&o,auto&&v)->enable_if_t<!is_constructible_v<string,decltype(v)>,decltype(o<<*end(v))>{int f=0,u=&o==&cerr&&o<<"[";for(auto&&x:v)(f++?o<<", "+!u:o)<<x;return u?o<<"]":o;}
auto operator<<(ostream&o,auto&&t)->decltype(o<<get<0>(t)){int f=0,u=&o==&cerr&&o<<"<";apply([&](auto&...x){(((f++?o<<", "+!u:o)<<x),...);},t);return u?o<<">":o;}
#ifdef BIZON
	#define rr(...) [](auto&&...x){ cerr << boolalpha << "\e[1;38;5;68m" << #__VA_ARGS__ << " "; int _=0; ((cerr<<"\e[0;38;5;61m"<<",="[!_++]<<"\e[0m "<<x),...)<<endl; }(__VA_ARGS__);
#else
	#define rr(...) ;
	#define endl '\n'
#endif
#define bb(c) begin(c), end(c)
#define ff(T, name, ...) function<T(__VA_ARGS__)> name = [&](__VA_ARGS__)->T
#define jj(...) __VA_ARGS__; [](auto&...x){(cin>>...>>x);}(__VA_ARGS__);
#define ii(...) int jj(__VA_ARGS__)
using ll = long long;
 
 
void run_case(const size_t ____case) { // rr(____case)
	ii(n)
	vector<ll> cnt(n);
	for(auto &_ : cnt) cin>>_;
	
	if (n >= 45) {cout << "NO"<<endl; return;}
	vector<ll> f(60);
	f[0] = f[1] = 1;
	for(int i=2; i<size(f); ++i) {
		f[i] = f[i-1] + f[i-2];
	}
	
	
	ll sum = accumulate(bb(cnt), 0LL);
	
	using MS = bitset<60>;
	
	map<int, MS> pf;
	
	auto gg = [&](ll x) {
		MS cur{};
		for(int k=size(f)-1; k>=0; --k) {
			if(x >= f[k]) {
				assert(k > 0);
				x -= f[k];
				cur[k] = true;
			}
		}
		return cur;
	};
	
	for(auto x : cnt) {
		pf[x] = gg(x);
		pf[x - 1] = gg(x - 1);
	}
	
	for(int p1=0; p1<n; ++p1) {
		cnt[p1]--;
		
		MS u{};
		bool ok = true;
		for(int i=0; i<n; ++i) {
			ll x = cnt[i];
			auto mx = pf[x];
			
			if((mx & u).count()) {
				ok = false;
			}
			
			if(i == p1) {
				if(mx[1]) ok = false;
			}
			
			u |= mx;
		}
		
		if(ok) {
			int i = size(f) - 1;
			while(i>0 && u[i] == 0) --i;
			while(i>0) {
				if(!u[i]) ok = false;
				--i;
			}
		}
		
		if(ok) {
			cout << "YES" << endl;
			return ;
		}
		
		cnt[p1]++;
	}
	
	cout << "NO"<<endl;
	
}
 
int main() {
	if(auto f="in.txt"; fopen(f,"r") && freopen(f,"r",stdin));
	cin.tie(0)->sync_with_stdio(0);
	
	size_t tn = 1; cin>>tn;
	for(size_t t=1; t<=tn; ++t) run_case(t);
	
	return 0;
}