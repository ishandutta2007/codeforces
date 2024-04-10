#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#define fr(a,b,c) for (a=b;a<=c;a++)
#define frr(a,b,c) for (a=b;a>=c;a--)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define F first
#define S second
#define oo 1000111222
using namespace std;
typedef long long ll;
const int dx[]={-1,0,1,0,-1,1,1,-1};
      int dy[]={0,1,0,-1,1,1,-1,-1};
struct widget
{
	string name,type;
	int bor,spa,num,list[111];
	long long x,y;
	void debug()
	{
		cout << type << " " << name << " " << x << " " << y << " " << bor << " " << spa << " " << num << endl;
	}
};

vector <widget> a;
int A,d[111];

int conv(string ss)
{
	stringstream t;
	int x;
	t << ss;
	t >> x;
	return x;
}

int find(string s)
{
	int i;
	fr(i,0,int(a.size())-1)
		if (a[i].name==s) return i;
	return -1;
}

void calc(int z)
{
	int i,C;
	widget c,b=a[z];
	d[z]=1;
	fr(i,1,b.num)
	{
		C=b.list[i];
		if (!d[C]) calc(C);
		if (b.type=="HBox")
		{
			b.x+=a[C].x;
			b.y=max(b.y,a[C].y);
		}
		else
			if (b.type=="VBox")
			{
				b.x=max(b.x,a[C].x);
				b.y+=a[C].y;
			}
	}
	if (b.num)
	{
		if (b.type=="HBox")
		{
			b.y+=b.bor*2;
			b.x+=b.bor*2+b.spa*(b.num-1);
		}
		else
			if (b.type=="VBox")
			{
				b.x+=b.bor*2;
				b.y+=b.bor*2+b.spa*(b.num-1);
			}
	}
	a[z]=b;
}

bool cmp(widget i,widget j)
{
	return i.name<j.name;
}

int main()
{
	//freopen("b.in.1","r",stdin);
	int n,i,l,B,C;
	string s,ss;
	widget b,c;
	cin >> n;
	while (n--)
	{
		cin >> s;
		b.x=b.y=b.spa=b.bor=b.num=0; 
		if (s=="Widget") 
		{
			b.type=s;
			cin >> s;
			l=s.length();
			fr(i,0,l-1)	if (s[i]=='(') break;
			b.name=s.substr(0,i); 
			s.erase(0,i+1);
			
			l=s.length();
			fr(i,0,l-1) if (s[i]==',') break;
			ss=s.substr(0,i);
			b.x=conv(ss);
			s.erase(0,i+1);
			
			l=s.length();
			fr(i,0,l-1) if (s[i]==',') break;
			ss=s.substr(0,i);
			b.y=conv(ss);
			s.erase(0,i+1);
			
			a.push_back(b);
		}
		else
			if (s=="VBox" || s=="HBox")
			{
				b.type=s; 
				cin >> b.name;
				a.push_back(b);
			}
			else
			{
				l=s.length();
				fr(i,0,l-1) if (s[i]=='.') break;
				b.name=s.substr(0,i);
				B=find(b.name);
				s.erase(0,i+1);
				
				if (s[0]=='p')
				{
					s.erase(0,5);
					c.name=s.substr(0,s.length()-1);
					C=find(c.name); 
					a[B].num++;
					a[B].list[a[B].num]=C;
				}
				else
				{
					if (s[4]=='b')
					{
						s.erase(0,11);
						ss=s.substr(0,s.length()-1);
						a[B].bor=conv(ss);
					}
					else
					{
						s.erase(0,12);
						ss=s.substr(0,s.length()-1);
						a[B].spa=conv(ss);
					}
				}
			}
	}
	A=a.size();
	fr(i,0,A-1) if (!d[i]) calc(i);
	sort(a.begin(),a.end(),cmp);
	fr(i,0,A-1) cout << a[i].name << " " << a[i].x << " " << a[i].y << endl;
	return 0;
}