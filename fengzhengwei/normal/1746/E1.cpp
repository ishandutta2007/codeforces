#include<bits/stdc++.h>
namespace ifzw{
#define ll long long 
#define dd double
#define LL __int128
#define ld long double
#define ull unsigned ll 
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
char ST;
int ask(vector<int>v)
{
	cout<<"? "<<v.size()<<" ";
	for(auto it:v)cout<<it<<" ";
	puts("");
	fflush(stdout);
	char c;
	while((c=getchar())!='Y'&&(c!='N'));
	return c=='Y';
}
int check(int x)
{
	cout<<"! "<<x<<"\n";
	fflush(stdout);
	char c;
	while((c=getchar())!=')'&&(c!='('));
	if(c==')')exit(0);
	return 0;
}
vector<int>rem;
vector<int> operator+(const vector<int>&A,const vector<int>&B)
{
	vector<int>C=A;
	for(auto it:B)C.push_back(it);
	return C;
}
char ED;
int main(){
//	cout<<sizeof(f)/1024/1024<<"$\n";// 191 
//	freopen("a.in","r",stdin);
	int n=read();
	for(int i=1;i<=n;i++)rem.push_back(i);
	while(rem.size()>=4)
	{
		vector<int>v[4];
		int ct=0;
		for(auto it:rem)
			v[(ct++)%4].push_back(it);
		int A=ask(v[0]+v[1]),B=ask(v[0]+v[2]);
		if(A&&B)rem=v[0]+v[1]+v[2];
		if(!A&&!B)rem=v[1]+v[2]+v[3];
		if(A&&!B)rem=v[0]+v[1]+v[3];
		if(!A&&B)rem=v[0]+v[2]+v[3];
	}
	int x=0,y=0;
	if(rem.size()==1)check(rem[0]);
	if(rem.size()==2)x=rem[0],y=rem[1];
	if(rem.size()==3)
	{
		int A=rem[0],t=ask({A});
		if(t)
		{
			t=ask({rem[1]});
			if(t)x=rem[0],y=rem[1];
			else x=rem[0],y=rem[2];
		}
		else 
		{
			t=ask({A});
			if(!t)x=rem[1],y=rem[2];
			else 
			{
				t=ask({rem[1]});
				if(t)x=rem[0],y=rem[1];
				else x=rem[0],y=rem[2];
			}
		}
	}
	check(x),check(y);
	pc('1',1);
	return 0;
}

}signed main(){return ifzw::main();}