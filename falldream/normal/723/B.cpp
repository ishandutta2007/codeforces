#include<iostream>
#include<cstdio>
#define INF 2000000000
#define ll long long
#define MAXN 255
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char s[MAXN+10];
bool yes=false;
int nown=0,maxn=0,in=0,n;

void renew()
{
	if(nown==0) return;
	if(!yes)
	maxn=max(maxn,nown);
	if(yes)
	in++;
	nown=0;
}

int main()
{
	n=read();
	cin.getline(s,n+10);
	for(int i=0;s[i];i++)
	{
		if(s[i]=='(')
		{
			renew();
			yes=true;
		}
		else
		    if(s[i]==')')
		    {
		    	renew();
		    	yes=false;
		    }
		    else
		        if(s[i]=='_')
		        {
                     renew();
		        }
		        else
		           nown++;
	}
	renew();
	cout<<maxn<<" "<<in<<endl;
	return 0;
}