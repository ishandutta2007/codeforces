#include<bits/stdc++.h>
#define ll long long
#define dd long double
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
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
int T,sps;//stone pos 
//012 
// 
vector<int> to(int l,int r)
{
	vector<int>v;
	v.clear();
	for(int i=l;i<=r;i++)v.push_back(i);
	return v;
}
int ask(vector<int>a,vector<int>b)// 
{
	cout<<"? "<<a.size()<<" "<<b.size()<<"\n";
	for(auto it:a)cout<<it<<" ";
	puts("");
	for(auto it:b)cout<<it<<" ";
	puts("");
	fflush(stdout);
	char s[55];
	scanf("%s",s);
	if(s[0]=='F')return 0;
	if(s[0]=='S')return 1;
	if(s[0]=='E')return 2;
	assert(0);
	return -1;
}
void run(int l,int r)// 
{
	if(l==r)return sps=l,void();
	int mid=(l+r-1)>>1;
	int tr=mid+(mid-l+1);
	int A=ask(to(l,mid),to(mid+1,tr));
	if(A==0||A==2)run(l,mid);
	else run(mid+1,tr);
	if(tr!=r)
		if(ask(to(sps,sps),to(r,r))==1)sps=r;
}
int main(){
	T=read();
	//k 
	while(T--)
	{
		int n=read(),k=read();
		sps=0;
		run(1,n);
		// 
		if(sps!=1&&ask(to(1,1),to(sps,sps))!=2)
		{
			cout<<"! "<<1<<"\n";
			fflush(stdout);
			continue;
		}
		// 
		int nt=1,nlen=1;
		while(nlen)
		{
			if(nt+nlen>n||ask(to(1,nlen),to(nt+1,nt+nlen))!=2)nlen/=2;
			else nt+=nlen,nlen*=2;
		}
		cout<<"! "<<nt+1<<"\n";
		fflush(stdout);
		continue;
	}
	pc('1',1);
	return 0;
}