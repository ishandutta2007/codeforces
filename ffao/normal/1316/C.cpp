#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <memory.h>
#include <cmath>
#include <array>

using namespace std;

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

typedef unsigned long long ull;

typedef long long ll;

namespace IO {
    const int BUFFER_SIZE = 1 << 15;
 
    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;
 
    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;
 
        if (input_len == 0)
            input_buffer[0] = EOF;
    }
 
    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            _update_input_buffer();
 
        return input_buffer[advance ? input_pos++ : input_pos];
    }
 
    template<typename T>
    inline void read_int(T &number) {
        bool negative = false;
        number = 0;
 
        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;
 
        do {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));
 
        if (negative)
            number = -number;
    }
 
    template<typename T, typename... Args>
    inline void read_int(T &number, Args &... args) {
        read_int(number);
        read_int(args...);
    }
}

using uint=unsigned;
using ull=unsigned long long;
template<class t> using vc=vector<t>;
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)

#define a first
#define b second
#define si(x) int(x.size())

struct modinfo{uint mod,root;};
template<modinfo const&ref>
struct modular{
	static constexpr uint const &mod=ref.mod;
	static modular root(){return modular(ref.root);}
	uint v;
	//modular(initializer_list<uint>ls):v(*ls.bg){}
	modular(ll vv=0){s(vv%mod+mod);}
	modular& s(uint vv){
		v=vv<mod?vv:vv-mod;
		return *this;
	}
	modular operator-()const{return modular()-*this;}
	
	modular&operator-=(const modular&rhs){return s(v+mod-rhs.v);}
	modular&operator*=(const modular&rhs){
		v=ull(v)*rhs.v%mod;
		return *this;
	}
	
	modular operator-(const modular&rhs)const{return modular(*this)-=rhs;}
	modular operator*(const modular&rhs)const{return modular(*this)*=rhs;}
	
	modular pow(int n)const{
		modular res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}
	modular inv()const{return pow(mod-2);}
	
};

//size of input must be a power of 2
//output of forward fmt is bit-reversed
//output elements are in the range [0,mod*4)
//input of inverse fmt should be bit-reversed
template<class mint>
void inplace_fmt(vector<mint>&f,bool inv){
	const int n=si(f);
	static const int L=22;
	static mint g[L],ig[L],p2[L];
	if(g[0].v==0){
		rng(i,0,L){
			mint w=-mint::root().pow(((mint::mod-1)>>(i+2))*3);
			g[i]=w;
			ig[i]=w.inv();
			p2[i]=mint(1<<i).inv();
		}
	}
	static constexpr uint mod2=mint::mod*2;
	if(!inv){
		int b=n;
		if(b>>=1){//input:[0,mod)
			rng(i,0,b){
				uint x=f[i+b].v;
				f[i+b].v=f[i].v+mint::mod-x;
				f[i].v+=x;
			}
		}
		if(b>>=1){//input:[0,mod*2)
			mint p=1;
			for(int i=0,k=0;i<n;i+=b*2){
				rng(j,i,i+b){
					uint x=(f[j+b]*p).v;
					//f[j].v=(f[j].v<mint::mod?f[j].v:f[j].v-mint::mod);
					f[j+b].v=f[j].v+mint::mod-x;
					f[j].v+=x;
				}
				p*=g[__builtin_ctz(++k)];
			}
		}
		while(b){
			if(b>>=1){//input:[0,mod*3)
				mint p=1;
				for(int i=0,k=0;i<n;i+=b*2){
					rng(j,i,i+b){
						uint x=(f[j+b]*p).v;
						//f[j].v=(f[j].v<mint::mod?f[j].v:f[j].v-mint::mod);
						f[j+b].v=f[j].v+mint::mod-x;
						f[j].v+=x;
					}
					p*=g[__builtin_ctz(++k)];
				}
			}
			if(b>>=1){//input:[0,mod*4)
				mint p=1;
				for(int i=0,k=0;i<n;i+=b*2){
					rng(j,i,i+b){
						uint x=(f[j+b]*p).v;
						f[j].v=(f[j].v<mod2?f[j].v:f[j].v-mod2);
						f[j+b].v=f[j].v+mint::mod-x;
						f[j].v+=x;
					}
					p*=g[__builtin_ctz(++k)];
				}
			}
		}
	}else{
		int b=1;
		if(b<n/2){//input:[0,mod)
			mint p=1;
			for(int i=0,k=0;i<n;i+=b*2){
				rng(j,i,i+b){
					ull x=f[j].v+mint::mod-f[j+b].v;
					f[j].v+=f[j+b].v;
					f[j+b].v=x*p.v%mint::mod;
				}
				p*=ig[__builtin_ctz(++k)];
			}
			b<<=1;
		}
		for(;b<n/2;b<<=1){
			mint p=1;
			for(int i=0,k=0;i<n;i+=b*2){
				rng(j,i,i+b/2){//input:[0,mod*2)
					ull x=f[j].v+mod2-f[j+b].v;
					f[j].v+=f[j+b].v;
					f[j].v=(f[j].v)<mod2?f[j].v:f[j].v-mod2;
					f[j+b].v=x*p.v%mint::mod;
				}
				rng(j,i+b/2,i+b){//input:[0,mod)
					ull x=f[j].v+mint::mod-f[j+b].v;
					f[j].v+=f[j+b].v;
					//f[j].v=(f[j].v)<mod2?f[j].v:f[j].v-mod2;
					f[j+b].v=x*p.v%mint::mod;
				}
				p*=ig[__builtin_ctz(++k)];
			}
		}
		if(b<n){//input:[0,mod*2)
			rng(i,0,b){
				uint x=f[i+b].v;
				f[i+b].v=f[i].v+mod2-x;
				f[i].v+=x;
			}
		}
		mint z=p2[__lg(n)];
		rng(i,0,n)f[i]*=z;
	}
}

int n,m,p;

namespace arbitrary_convolution{
    constexpr modinfo base0{167772161,3};//243};
	constexpr modinfo base1{415236097,5};//73362476};
	constexpr modinfo base2{463470593,3};//428228038};
	// constexpr modinfo base0{167772161,3};//2^25 * 5 + 1
	// constexpr modinfo base1{469762049,3};//2^26 * 7 + 1
	// constexpr modinfo base2{754974721,11};//2^24 * 45 + 1
	// constexpr modinfo base0{1045430273,3};//2^20 * 997 + 1
	// constexpr modinfo base1{1051721729,6};//2^20 * 1003 + 1
	// constexpr modinfo base2{1053818881,7};//2^20 * 1005 + 1
	using mint0=modular<base0>;
	using mint1=modular<base1>;
	using mint2=modular<base2>;
	template<class t>
	vc<t> sub(const vc<unsigned>&x,const vc<unsigned>&y,bool same=false){
		int n=si(x)+si(y)-1;
		int s=1;
		while(s<n)s*=2;
		vc<t> z(s);rng(i,0,si(x))z[i]=x[i];
		inplace_fmt(z,false);
		if(!same){
			vc<t> w(s);rng(i,0,si(y))w[i]=y[i];
			inplace_fmt(w,false);
			rng(i,0,s)z[i]*=w[i];
		}else{
			rng(i,0,s)z[i]*=z[i];
		}
		inplace_fmt(z,true);z.resize(n);
		return z;
	}
	vc<uint> multiply(const vc<unsigned>&x,const vc<unsigned>&y,bool same=false){
		auto d0=sub<mint0>(x,y,same);
		auto d1=sub<mint1>(x,y,same);
		auto d2=sub<mint2>(x,y,same);
		int n=si(d0);
		vc<uint> res(n);
		static const mint1 r01=mint1(mint0::mod).inv();
		static const mint2 r02=mint2(mint0::mod).inv();
		static const mint2 r12=mint2(mint1::mod).inv();
		static const mint2 r02r12=r02*r12;
		static const uint w1=(mint0::mod) % p;
		static const uint w2=(w1*1ull*(mint1::mod)) % p;
		rng(i,0,n){
			ull a=d0[i].v;
			ull b=(d1[i].v+mint1::mod-a)*r01.v%mint1::mod;
			ull c=((d2[i].v+mint2::mod-a)*r02r12.v+(mint2::mod-b)*r12.v)%mint2::mod;
			res[i]=(a+b*w1+c*w2)%p;
		}
		return res;
	}
}
using arbitrary_convolution::multiply;

vector<uint> a;
vector<uint> b;

void solve()
{
    IO::read_int(n,m,p);
    a.resize(n); b.resize(m);

    rng(i,0,n) IO::read_int(a[i]);
    rng(i,0,m) IO::read_int(b[i]);
    
    vector<uint> c = multiply(a, b, false);

    for (int i = 0; ; i++) {
        if (c[i]) {
            printf("%d\n", i);
            return;
        }
    }
}

int main() {

    solve();
}