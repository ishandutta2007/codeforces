#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
#include<cstring>
using namespace std;
unsigned int n,m;
unsigned long long L,R;
set<pair<unsigned int,unsigned int> > s;
vector<unsigned int> v[200001];
namespace io {
	const int __SIZE = (1 << 21) + 1;
	char ibuf[__SIZE], *iS, *iT, obuf[__SIZE], *oS = obuf, *oT = oS + __SIZE - 1, __c, qu[55]; int __f, qr, _eof;
	#define Gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	inline void flush () { fwrite (obuf, 1, oS - obuf, stdout), oS = obuf; }
	inline void gc (char &x) { x = Gc(); }
	inline void pc (char x) { *oS ++ = x; if (oS == oT) flush (); }
	inline void pstr (const char *s) { int __len = strlen(s); for (__f = 0; __f < __len; ++__f) pc (s[__f]); }
	inline void gstr (char *s) { for(__c = Gc(); __c < 32 || __c > 126 || __c == ' ';)  __c = Gc();
		for(; __c > 31 && __c < 127 && __c != ' ' && __c != '\n' && __c != '\r'; ++s, __c = Gc()) *s = __c; *s = 0; }
	template <class I> inline bool gi (I &x) { _eof = 0;
		for (__f = 1, __c = Gc(); (__c < '0' || __c > '9') && !_eof; __c = Gc()) { if (__c == '-') __f = -1; _eof |= __c == EOF; }
		for (x = 0; __c <= '9' && __c >= '0' && !_eof; __c = Gc()) x = x * 10 + (__c & 15), _eof |= __c == EOF; x *= __f; return !_eof; }
	template <class I> inline void print (I x) { if (!x) pc ('0'); if (x < 0) pc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10; while (qr) pc (qu[qr --]); }
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
} using io::pc; using io::gc; using io::pstr; using io::gstr; using io::gi; using io::print;
int main()
{
    gi(n),gi(m),gi(L),gi(R);
    unsigned int lim=max(n,m);
    for(unsigned int i=1;i<=lim;++i)
        for(unsigned int j=i;j<=lim;j+=i)
            v[j].emplace_back(i);
    unsigned int l=m+1,r=m;
    for(int i=1;i<=n;++i)
    {
        if((L+i-1)/i>min(R/i,1ull*m))
        {
            pstr("-1\n");
            continue;
        }
        unsigned long long tmp=(L+i-1)/i;
        while(l>tmp)
        {
            --l;
            for(unsigned int j:v[l])
                s.emplace(j,l);
        }
        tmp=min(R/i,1ull*m);
        while(r>tmp)
        {
            for(unsigned int j:v[r])
                s.erase({j,r});
            --r;
        }
        bool flag=0;
        for(unsigned int j:v[i])
        {
            set<pair<unsigned int,unsigned int> >::iterator it=s.upper_bound({j,1000000});
            if(it==s.end())
                break;
            unsigned long long a=1ull*i/j*it->first,b=1ull*it->second/it->first*j;
            if(a<=n)
            {
                print(i);
                pstr(" ");
                print(it->second);
                pstr(" ");
                print(a);
                pstr(" ");
                print(b);
                pstr("\n");
                flag=1;
                break;
            }
        }
        if(!flag)
            pstr("-1\n");
    }
    return 0;
}