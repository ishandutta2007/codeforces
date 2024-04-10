#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a;
		a=a*a,b>>=1;
	}return res;
}

int n,k,s1[100],s2[100];

int del(int a,int b)
{
	int len1=0,len2=0,res=0;//int aa=a,bb=b;
	while(a)s1[++len1]=a%k,a/=k;
	while(b)s2[++len2]=b%k,b/=k;
	int len=max(len1,len2);
	for (int i=len1+1;i<=len;i++)s1[i]=0;
	for (int i=len2+1;i<=len;i++)s2[i]=0;
	for (int i=1;i<=len;i++)
		res+=(s1[i]-s2[i]+k)%k*poww(k,i-1);
//	cout<<"-1"<<' '<<aa<<' '<<bb<<' '<<res<<endl;
	return res;
}

int add(int a,int b)
{
	int len1=0,len2=0,res=0;
	while(a)s1[++len1]=a%k,a/=k;
	while(b)s2[++len2]=b%k,b/=k;
	int len=max(len1,len2);
	for (int i=len1+1;i<=len;i++)s1[i]=0;
	for (int i=len2+1;i<=len;i++)s2[i]=0;
	for (int i=1;i<=len;i++)
		res+=(s1[i]+s2[i])%k*poww(k,i-1);
//	cout<<"1"<<' '<<aa<<' '<<bb<<' '<<res<<endl;
	return res;
}

signed main()
{
	WT
	{
		n=read(),k=read();int now=0,opt=1;
//		cout<<del(2,0)<<endl;
		for (int i=0;i<n;i++)
		{
			int p;
			if (opt==1)
				p=add(i,now);//,cout<<i<<' '<<now<<' '<<p<<endl;
			else p=del(now,i);
			cout<<p<<endl;
			int x;cin>>x;
			if (x)break;
			now=del(p,now);//cout<<now<<"/kel\n";
			opt*=-1;
		}
	}
	return 0;
}