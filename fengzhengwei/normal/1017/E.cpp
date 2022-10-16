#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=2e5+5;
int n,m;
struct point{ll x,y;bool operator<(const point&w)const{return x==w.x?y<w.y:x<w.x;};};
ll cross(point a,point b,point c){return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);}
vector<point>a,b;
int stk[xx];
void get(vector<point> &v)
{
	vector<point> s;
	sort(v.begin(),v.end());
	int top=0;
	for(int i=0;i<v.size();i++)
	{
		while(top>1&&cross(v[stk[top-1]],v[stk[top]],v[i])>=0)top--;
		stk[++top]=i;
	}
	int now=top;
	for(int i=v.size()-2;i>=0;i--)
	{
		while(top>now&&cross(v[stk[top-1]],v[stk[top]],v[i])>=0)top--;
		stk[++top]=i;
	}
	for(int i=1;i<=top;i++)s.push_back(v[stk[i]]);
	swap(v,s);
}
struct pr
{
	double x,y;
	bool operator==(const pr&w)const{return abs(x-w.x)<=1e-4&&abs(y-w.y)<=1e-4;}
	bool operator!=(const pr&w)const{return !(*this==w);}
}e[xx],w[xx];
double dis(point a,point b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
double ang(double a,double b,double c){return (c*c+b*b-a*a)/(2*b*c);}
int nxt[xx];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		a.push_back((point){x,y});
	}
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		b.push_back((point){x,y});
	}
	get(a);get(b);
	a.push_back(a[1]);
	b.push_back(b[1]);
//	for(auto it:a)
//	{
//		cout<<"("<<it.x<<","<<it.y<<")\n";
//	}
//	puts("");
//	for(auto it:b)
//	{
//		cout<<"("<<it.x<<","<<it.y<<")\n";
//	}
//	return 0;
	int tta=0,ttb=0;
	for(int i=0;i<a.size()-2;i++)
	{
		tta++;
		e[tta].x=dis(a[i],a[i+1]);
		e[tta].y=ang(dis(a[i],a[i+2]),dis(a[i],a[i+1]),dis(a[i+1],a[i+2])); 
	}
	for(int i=0;i<b.size()-2;i++)
	{
		ttb++;
		w[ttb].x=dis(b[i],b[i+1]);
		w[ttb].y=ang(dis(b[i],b[i+2]),dis(b[i],b[i+1]),dis(b[i+1],b[i+2])); 
	}
	int p=0;
	for(int i=2;i<=ttb;i++)
	{
		while(p&&w[p+1]!=w[i])p=nxt[p];
		if(w[p+1]==w[i])p++;
		nxt[i]=p;
	}
	for(int i=1;i<=tta;i++)e[i+tta]=e[i];
	tta*=2;
	for(int i=1;i<=tta;i++)
	{
		while(p&&w[p+1]!=e[i])p=nxt[p];
		if(w[p+1]==e[i])p++;
		if(p==ttb){puts("YES");exit(0);}
	}
	puts("NO");
	return 0;
}