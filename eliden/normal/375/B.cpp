#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<#x<<": "<<x<<endl;
const int sz=5e3;

int n,m,a[sz];
int range[sz][sz];
int fin[sz];
char s[sz+1];
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,0,m)
		a[i]=0;
	rep(i,0,m)
		rep(j,0,m)
		range[i][j]=0;
	rep(i,0,n)
	{
	    scanf("%s",s);
		int l=-1,r=-1;
		rep(j,0,m)
			if(s[j]=='1')
			{
				if(l==-1)
					l=j;
				r=j;
			}
			else if(l!=-1)
			{
				++range[l][r];
				l=-1;
				r=-1;
			}
		if(l!=-1)
		    ++range[l][r];
				
	}
	rep(i,0,m)
		fin[i]=0;
	int best=0;
	rep(i,0,m)
	{
		rep(j,0,m)
			fin[j]+=range[i][j];
		int c=0;
		for(int j=m-1;j>=i;--j)
		{
			c+=fin[j];
			if(c*(j-i+1)>best)
				best=c*(j-i+1);
		}
	}
	printf("%d\n",best);
}