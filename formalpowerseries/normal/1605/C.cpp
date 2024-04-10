#include<bits/stdc++.h>
using namespace std;
int Abs(int x){return x>0?x:-x;}
int n;
char s[1000005];
void Solve()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int ans=1e9;
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=min(i+8,n);++j)
		{
			int a=0,b=0,c=0;
			for(int k=i;k<=j;++k)
			{
				if(s[k]=='a')	++a;
				if(s[k]=='b')	++b;
				if(s[k]=='c')	++c;
			}
			if(a>b && a>c)	ans=min(ans,j-i+1);
		}
	}
	printf("%d\n",ans==1e9?-1:ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)	Solve();
	return 0;
}