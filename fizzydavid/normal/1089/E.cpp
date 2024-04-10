#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
int n;
int main()
{
	cin>>n;
	if(n<=14)
	{
		vector<string> s; n-=2;
		for(int x='b';x<'h'&&n;++x)
		{
			string t="";
			t.pb(x); t.pb('1');
			s.pb(t),--n;
		}
		s.pb("h1");
		for(int i=2;i<=7&&n;++i)
		{
			string t="";
			t.pb('h'); t.pb(i+'0');
			s.pb(t); --n;
		}
		printf("a1");
		for(auto x:s) cout<<" "<<x;
		cout<<" h8\n";
		return 0;
	}
	if(n<=56)
	{
		vector<string> s;
		n-=14;
		for(int i=1;i<=7;++i)
		{
			string p="a",q="h";
			p.pb(i+48); q.pb(i+48);
			vector<string> o;
			o.pb(p);
			int g=min(n,6); n-=g;
			for(int f=1;f<=g;++f)
			{
				string s;
				s.pb('a'+f);
				s.pb(i+48);
				o.pb(s);
			}
			o.pb(q);
			if(i%2==0) reverse(o.begin(),o.end());
			for(auto t:o) s.pb(t);
		}
		s.pb("h8");
		if(n) throw "GG";
		for(auto r:s) cout<<r<<" ";
		return 0;
	}
	vector<string> s;
	s.pb("h8");
	s.pb("h7");
	s.pb("f7");
	s.pb("f8");
	s.pb("e8");
	s.pb("g8");
	s.pb("g7");
	s.pb("e7");
	s.pb("d7");
	s.pb("d8");
	s.pb("c8");
	s.pb("c7");
	s.pb("b7");
	s.pb("b8");
	s.pb("a8");
	s.pb("a7");
	for(int i=6;i>=1;--i)
	{
		vector<string> o;
		for(int j=0;j<8;++j)
		{
			string w;
			w.pb('a'+j);
			w.pb(i+'0');
			o.pb(w);
		}
		if(i&1) reverse(o.begin(),o.end());
		for(auto t:o) s.pb(t);
	}
	s.resize(n);
	s.pb("a1");
	reverse(s.begin(),s.end());
	set<string> pp;
	for(int i=0;i+1<s.size();++i)
		if(s[i][0]==s[i+1][0]||s[i][1]==s[i+1][1]);
		else throw "GG";
	for(auto o:s)
		pp.insert(o),
		cout<<o<<" ";
	if(pp.size()!=s.size()) throw "GG";
}