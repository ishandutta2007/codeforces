#include<iostream>
#include<cstdio>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}

char s[55][55],s2[55][55],ch;
int n,m,cnt=0;
struct ANS{
	int x,y;
}A[100005];

bool check(char a[55][55])
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]==ch) return 0;
	return 1;
}

void solve(char a[55][55])
{
	while(1)
	{
		bool ok=1;
		for(;ok;)
		{
			ok=0;
			for(int i=1;i<n;i++)
				for(int j=1;j<m;j++)
					if(a[i][j]=='L'&&a[i+1][j]=='L')
					{
						ok=1;A[++cnt]=(ANS){i,j};
						a[i][j]='U';a[i+1][j]='D';
						a[i][j+1]='U';a[i+1][j+1]='D';
					}	
		}	
		if(check(a)) break;
		for(ok=1;ok;)
		{
			ok=0;
			for(int i=1;i<n;i++)
				for(int j=1;j<m;j++)
					if(a[i][j]=='U'&&a[i][j+1]=='U')
					{
						ok=1;A[++cnt]=(ANS){i,j};
						a[i][j]='L';a[i+1][j]='L';
						a[i][j+1]='R';a[i+1][j+1]='R';
					}		
		}
		if(check(a)) break;
	}
}

int main()
{
	n=read();m=read();ch=n&1?'U':'L';
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)scanf("%s",s2[i]+1);
	solve(s);int pre=cnt;
	solve(s2);
	cout<<cnt<<endl;
	for(int i=1;i<=pre;i++) printf("%d %d\n",A[i].x,A[i].y);
	for(int i=cnt;i>pre;i--)    printf("%d %d\n",A[i].x,A[i].y);
	return 0;
}