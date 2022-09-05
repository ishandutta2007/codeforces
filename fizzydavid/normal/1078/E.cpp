//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
    char s[100000];
    int it, len;
    fastio() {it=len=0;}
    inline char get()
    {
        if (it<len) return s[it++]; it=0;
        len=fread(s, 1, 100000, stdin);
        if (len==0) return EOF; else return s[it++];
    }
    bool notend()
    {
        char c=get();
        while (c==' '||c=='\n') c=get();
        if (it>0) it--;
        return c!=EOF;
    }
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
    ll r=0; bool ng=0; char c; c=_buff.get();
    while (c!='-'&&(c<'0'||c>'9')) c=_buff.get();
    if (c=='-') ng=1, c=_buff.get();
    while (c>='0'&&c<='9') r=r*10+c-'0', c=_buff.get();
    return ng?-r:r;
}
template <class T> inline void putnum(T x)
{
    if (x<0) putchar('-'), x=-x;
    register short a[20]={}, sz=0;
    while (x) a[sz++]=x%10, x/=10;
    if(sz==0) putchar('0');
    for (int i=sz-1; i>=0; i--) putchar('0'+a[i]);
}
inline char getreal() {char c=_buff.get(); while (c<=32) c=_buff.get(); return c;}
ll qpow(ll x, ll k) {return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
string S;
void addcmd(string s, int times = 1)
{
	for (int i=0; i<times; i++) S += s;
}
const int Rc = 0;  //calc row
const int Rt = 1;  //transmission row
const int Rm = 2;  //memory row
char op[256];
int X, Y;
void move(char c)
{
	S += c;
	if (c=='r') X++;
	if (c=='u') Y++;
	if (c=='l') X--;
	if (c=='d') Y--;
}
void _move_to(int x, int y)
{
//	cerr<<"_move_to:"<<x<<","<<y<<endl;
	while (X<x) move('r');
	while (Y<y) move('u');
	while (X>x) move('l');
	while (Y>y) move('d');
}
void move_to(int x, int y)
{
	_move_to(X, Rt);
	_move_to(x, Rt);
	_move_to(x, y);
}
void copy(char c)
{
	move(c);
	S += "10";
	S.PB(op[c]);
	S += "t";
}
void _copy_to(int x,int y)
{
//	cerr<<"_copy_to "<<x<<","<<y<<endl;
	while (X<x) copy('r');
	while (Y<y) copy('u');
	while (X>x) copy('l');
	while (Y>y) copy('d');
}
void copy_to(int x, int y)
{
	_copy_to(X, Rt);
	_copy_to(x, Rt);
	_copy_to(x, y);
}
void copy(int ax, int ay, int bx, int by)
{
	move_to(ax, ay);
	copy_to(bx, by);
}
const int N = 31; //number of bits
const int M = 7;
const int Bt = 0;  //calculation temp
const int Bm = M; //temp variables
const int B0 = -1; //a
const int B1 = -1-N; //b
const string skip_0_to_right = "rlt";
const string try_right = "srt";
const string try_left = "slt";

void prework()
{
	addcmd("r");
	for (int t=0; t<2; t++)
	{
		addcmd("l", N+1);
		addcmd(try_right, N);
		addcmd("0l", N);
		addcmd("r", 2*N+2);
		addcmd(try_left, N+2);
		addcmd("u");
	}
	addcmd("d", 2);
	addcmd("l");
	X = Y = 0;
	for (int i=N-1; i>=0; i--)
	{
		copy(-i, 1, B1-i, Rm);
		copy(-i, 0, B0-i, Rm);
	}
}
void and_gate(int x, int y, int z)//z = x&y
{
	copy(x, Rm, 0, Rc);
	copy(y, Rm, 1, Rc);
	move_to(1, Rc);
	addcmd("0lt");
	copy(1, Rc, z, Rm);
}
void niubi_gate(int x, int y, int z)//z = !(x & !y)
{
	copy(x, Rm, 0, Rc);
	copy(y, Rm, 1, Rc);
	move_to(1, Rc);
	addcmd("1lt");
	copy(1, Rc, z, Rm);
}
void not_gate(int x, int y) //y = !x
{
	copy(x, Rm, 0, Rc);
	move_to(1, Rc);
	addcmd("01lt");
	copy(1, Rc, y, Rm);
}
void or_gate(int x, int y, int z) //z = x|y
{
	not_gate(x, Bt+0);
	not_gate(y, Bt+1);
	and_gate(Bt+0, Bt+1, Bt+2);
	not_gate(Bt+2, z);
}
void xor_gate(int x, int y, int z) //z = x^y
{
	niubi_gate(x, y, Bt+3);
	niubi_gate(y, x, Bt+4);
	and_gate(Bt+3, Bt+4, Bt+5);
	not_gate(Bt+5, z);
}
void add_gate(int x, int sum, int r) //(sum,r) += x
{
	and_gate(x, sum, Bt+6);
	or_gate(Bt+6, r, r);
	xor_gate(x, sum, sum);
}
void set0_gate(int x)
{
	move_to(x, Rm);
	addcmd("0");
}
int main()
{
	op['u'] = 'd';
	op['d'] = 'u';
	op['l'] = 'r';
	op['r'] = 'l';
	prework();
	int r = Bm+0;
	int sum = Bm+1;
	set0_gate(sum);
	set0_gate(r);
	for (int i=0; i<N; i++)
	{
		set0_gate(r);
		add_gate(B0-i, sum, r);
		add_gate(B1-i, sum, r);
		copy(sum, Rm, -i, -1);
		copy(r, Rm, sum, Rm);
	}
	move_to(0, -1);
	addcmd("l", N-1);
	addcmd(skip_0_to_right, N);	
	printf("%s\n",S.c_str());
	return 0;
}