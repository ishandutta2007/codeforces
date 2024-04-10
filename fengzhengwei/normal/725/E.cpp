#include<bits/stdc++.h>
#define ll long long
#define dd double
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
const int xx=2e5+5;
int n;
vector<int>die;
int cr[xx],a[xx];//10 
int mn=1e9;
ll dlt[xx];
ll sum[xx];
int MM[xx];
void get(int C)
{
	if(!cr[C])return;
	if(!C)return;
	//0~C-a[t] 
	// 
	int t=MM[C];
//	upper_bound(a+1,a+n+1,C)-a-1;
//	cout<<C<<" "<<dlt[C]<<"!!\n";
//	cout<<a[t]<<"@!#\n";
	// 
	// 
	// 
	
	if(C-a[t]<die[0])return;
	int r=upper_bound(die.begin(),die.end(),C-a[t])-die.begin()-1;
//	cout<<die[r]<<"SADASD\n";
	mn=min(mn,C-die[r]);
	get(C-dlt[C]);
}
// 
int main(){
	int C=read();
	n=read();
	a[0]=1e9;sum[0]=1e9;
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int ntt=0,nl=0;
	a[n+1]=1e9;
	cr[0]=1;
	for(int i=1;i<=C;i++)
	{
		while(i>=a[ntt+1])ntt++,nl=ntt;
		while(nl!=0&&nl!=1&&i-(sum[ntt]-sum[nl-1])>=a[nl]/*>=sum[ntt]-sum[nl-2]*/)nl--;
		if(!ntt)
		{
			cr[i]=0,dlt[i]=0;
			if(!cr[i])die.push_back(i);
			continue;
		}
		if(nl==1&&i-(sum[ntt]-sum[nl-1])!=0)
		{
			cr[i]=0,dlt[i]=0;
			if(!cr[i])die.push_back(i);
			continue;
		}
		cr[i]=cr[i-(sum[ntt]-sum[nl-1])];
		if(!cr[i])die.push_back(i);
		dlt[i]=sum[ntt]-sum[nl-1];
		MM[i]=nl;
		// 
//		cout<<i<<" "<<cr[i]<<" "<<dlt[i]<<"!!\n";
//		cout<<i<<" "<<cr[i]<<" "<<nl<<" "<<"!!\n";
//		cout<<i<<' '<<cr[i]<<" "<<a[ntt]<<"!!\n";
	}
//	cout<<cr[65634-28491]<<"\n";
//	for(auto it:die)cout<<it<<" ";
//	puts("");
	if(!cr[C])
	{
		puts("0");
		exit(0);
	}
	
	if(!die.size())puts("Greed is good"),exit(0);
	get(C);
	
	if(mn>=1e9)puts("Greed is good"),exit(0);
	cout<<mn<<"\n";
	pc('1',1);
	return 0;
}