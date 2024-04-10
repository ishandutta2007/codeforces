#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[505][505];
int main(){
	int T;
	scanf("%d",&T);
	srand(time(NULL));
	while(T-->0)
	{
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;++i)	scanf("%s",s[i]+1);
		for(int i=1;i<=m;++i)
		{
			if(i%3==1)
			{
				for(int j=1;j<=n;++j)	s[j][i]='X';
			}
		}
		for(int i=1;i<=m;i+=3)
		{
			if(i==m)	break;
			if(i+1==m)	break;
			if(i+2==m)
			{
				for(int j=1;j<=n;++j)
				{
					if(s[j][i+1]=='X')	s[j][i+2]='X';
					if(s[j][i+2]=='X')	s[j][i+1]='X';
				}
				break;
			}
			for(int j=1;j<=n;++j)	if(s[j][i+1]=='X' && s[j][i+2]=='X')	goto End;
			for(int j=1;j<=n;++j)
			{
				if(s[j][i+1]=='X')
				{
					s[j][i+2]='X';
					goto End;
				}
				if(s[j][i+2]=='X')
				{
					s[j][i+1]='X';
					goto End;
				}
			}
			s[1][i+1]=s[1][i+2]='X';
			End:;
		}
		for(int i=1;i<=n;++i)	puts(s[i]+1);
	}
	return 0;
}