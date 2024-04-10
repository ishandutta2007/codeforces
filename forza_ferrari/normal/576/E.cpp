#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
struct edge
{
    int x,y;
}e[500001];
int root,n,m,col,q,bin[51][500001<<1|1],s[51][500001<<1|1],num[500001],cnt[500001],now[500001],top,tot,ls[500001<<1|1],rs[500001<<1|1];
struct element
{
    int x,y,w;
};
vector<element> v[500001<<1|1];
vector<pair<int,int> > c[500001];
pair<element,int> tmp[500001<<1|1];
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
inline int anc(int k,int tag)
{
    if(!bin[tag][k])
        return k;
    return anc(bin[tag][k],tag);
}
inline element link(int x,int y,int tag)
{
    x=anc(x,tag);
    y=anc(y,tag);
    if(x==y)
        return {0,0,0};
    if(s[tag][x]<s[tag][y])
        x^=y^=x^=y;
    bin[tag][y]=x;
    s[tag][x]+=s[tag][y];
    return {x,y,tag};
}
inline void cut(element p)
{
    if(!p.x||!p.y||!p.w)
        return;
    bin[p.w][p.y]=0;
    s[p.w][p.x]-=s[p.w][p.y];
}
inline void update(int nl,int nr,int l,int r,int &k,element p)
{
    if(nl>nr)
        return;
    if(!k)
        k=++tot;
    if(l>=nl&&r<=nr)
    {
        v[k].resize(v[k].size()+1,p);
        return;
    }
    int mid=(l+r)>>1;
    if(nl<=mid)
        update(nl,nr,l,mid,ls[k],p);
    if(nr>mid)
        update(nl,nr,mid+1,r,rs[k],p);
}
inline void query(int l,int r,int &k)
{
    if(!k)
        k=++tot;
    for(element i:v[k])
    {
        tmp[++top]={link(i.x,i.y+n,i.w),k};
        tmp[++top]={link(i.x+n,i.y,i.w),k};
    }
    if(l==r)
    {
        int x=e[num[l]].x,y=e[num[l]].y,tag=c[num[l]][cnt[num[l]]].first,t=c[num[l]][cnt[num[l]]+1].second;
        if(anc(x,tag)==anc(y,tag))
        {
            pstr("NO\n");
            if(now[num[l]])
                update(l+1,t-1,1,q,root,{x,y,now[num[l]]});
        }
        else
        {
            pstr("YES\n");
            update(l+1,t-1,1,q,root,{x,y,now[num[l]]=tag});
        }
        ++cnt[num[l]];
        while(top&&tmp[top].second==k)
        {
            cut(tmp[top].first);
            --top;
        }
        return;
    }
    int mid=(l+r)>>1;
    query(l,mid,ls[k]);
    query(mid+1,r,rs[k]);
    while(top&&tmp[top].second==k)
    {
        cut(tmp[top].first);
        --top;
    }
}
int main()
{
    gi(n),gi(m),gi(col),gi(q);
    for(int i=1;i<=col;++i)
        for(int j=1;j<=n<<1;++j)
            s[i][j]=1;
    for(int i=1;i<=m;++i)
        gi(e[i].x),gi(e[i].y);
    for(int i=1;i<=q;++i)
    {
        gi(num[i]);
        int tag;
        gi(tag);
        c[num[i]].resize(c[num[i]].size()+1,{tag,i});
    }
    for(int i=1;i<=m;++i)
        c[i].push_back({0,q+1});
    //if(n==1000&&m==10000&&col==1)
        //return 0;
    query(1,q,root);
    return 0;
}