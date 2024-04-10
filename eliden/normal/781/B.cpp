#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define repeq(i,a,b) for(int i=a;i<=b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
const int sz=1e5, infty=1<<30;
int n;
char s1[30], s2[30], f1[1000],f2[1000];
int num[26][26], q[26][26][1000], a[1000],b[1000],choice[1000];
int main()
{
	scanf("%d",&n);
	rep(i,0,26)
		rep(j,0,26)
		num[i][j]=0;
	rep(i,0,n)
	{
		scanf("%s%s",s1,s2);
		a[i]=s1[2]-'A';
		b[i]=s2[0]-'A';
		int x=s1[0]-'A', y=s1[1]-'A';
		f1[i]=s1[0], f2[i]=s1[1];
		q[x][y][num[x][y]]=i;
		++num[x][y];
		choice[i]=-1;
	}
	int col[26], need[26], id[1000];
	bool pos=true, cha[1000], mark[1000];
	for(int x=0;x<26 && pos;++x)
		for(int y=0;y<26 && pos;++y)
			if(num[x][y]>0)
			{
				rep(i,0,26)
					col[i]=0;
				rep(i,0,num[x][y])
				{
					id[i]=q[x][y][i];
					cha[i]=true;
					mark[i]=false;
				}
				rep(i,0,num[x][y])
				{
					choice[id[i]]=a[id[i]];
					++col[a[id[i]]];
				}
				bool done = false;
				while(!done)
				{
					done = true;
					rep(i,0,num[x][y])
						if(cha[i] && col[a[id[i]]]>1)
						{
							mark[i]=true;
							done = false;
						}
					rep(i,0,num[x][y])
						if(mark[i])
						{
							choice[id[i]]=b[id[i]];
							cha[i]=false;
							mark[i]=false;
							--col[a[id[i]]];
							++col[b[id[i]]];
						}
				}
				rep(i,0,num[x][y])
					if(col[choice[id[i]]]>1)
						pos=false;
			}
	if(!pos)
		printf("NO\n");
	else
	{
		printf("YES\n");
		rep(i,0,n)
		{
			printf("%c%c%c\n",f1[i],f2[i],choice[i]+'A');
		}
	}
}