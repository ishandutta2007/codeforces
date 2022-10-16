#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=100005;
struct node{ll x,y;bool operator<(const node&w)const{return x==w.x?y<w.y:x<w.x;}};
ll cross(node a,node b,node c){return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);}
#define mu multiset<node>::iterator
mu pre(mu it){return --it;}
mu suf(mu it){return ++it;}
int vs=0;
struct nod
{
	multiset<node>s;// 
	void c(){if((--s.end())->x==(----s.end())->x)s.erase(----s.end());}
	void u(mu it)//update 
	{
		if(it!=s.begin())
			while(pre(it)!=s.begin()&&cross(*pre(pre(it)),*pre(it),*it)>=0)s.erase(pre(it));
		if(suf(it)!=s.end())
			while(suf(suf(it))!=s.end()&&cross(*it,*suf(it),*suf(suf(it)))>=0)s.erase(suf(it));
	}
	void insert(node x)
	{
		if(s.size() < 2){s.insert(x);return;}
		mu it=s.lower_bound(x);
		if(it==s.begin()||it==s.end())u(s.insert(x));
		else if(cross(*pre(it),x,*it)<=0)u(s.insert(x));c();
	}
	bool check(node x)
	{
		if(s.size()<2)return 1;
		mu it=s.lower_bound(x);
		if(x.x==it->x&&x.y==it->y)return 0;
		if(it==s.begin()||it==s.end())return 1;
		else if(cross(*pre(it),x,*it)<0)return 1;
		return 0;
	}
}s1,s2;
int main(){
	node x;
	int m=read();
	while(m--)
	{
		int op=read();
		x.x=read(),x.y=read();
		if(op==1)
		{
			s1.insert(x);
			x.x*=-1,x.y*=-1;
			s2.insert(x);
		}
		else 
		{
			if(s1.check(x)){puts("NO");continue;}
			x.x*=-1,x.y*=-1;
			if(s2.check(x)){puts("NO");continue;}
			puts("YES");
		}
	}
	return 0;
}