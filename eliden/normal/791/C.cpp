#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define repeq(a,b,c) for(int a=b;a<=c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
typedef long long ll;
const int sz = 1e6;

void printcode(int code)
{
	if(code<26)
		printf("%ca ",((char)'A'+code));
	else
		printf("%cb ",((char)'A'+code-26));
}

int main()
{
	int n, k;
	int code[100], used[100];
	scanf("%d%d",&n,&k);
	int j = k-1;
	string eff;
	rep(i,0,k-1)
		code[i]=i;
	rep(i,0,n-k+1)
	{
		cin>>eff;
		if(eff[0]=='Y')
		{
			rep(x,0,100)
				used[x]=false;
			rep(x,i,j)
				used[code[x]]=true;
			bool found=false;
			for(int x=0;!found;++x)
				if(!used[x])
				{
					found=true;
					code[j]=x;
				}
		}
		else
			code[j]=code[i];
		++j;
	}
	rep(i,0,n)
		printcode(code[i]);
	printf("\n");
	
}