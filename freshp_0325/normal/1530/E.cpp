#include<bits/stdc++.h>
using namespace std;
int n;
char s[100005];
int cnt[28];
char trans(int x){return x+'a'-1;}
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%s",s+1);
		memset(cnt,0,sizeof cnt);
		n=strlen(s+1);
		for(int i=1;i<=n;++i)	++cnt[s[i]-'a'+1];
		int col=0,dt1=0;
		for(int i=1;i<=26;++i)
		{
			if(cnt[i])	++col;
			if(cnt[i]==1)	++dt1;
		}
		if(col==1)
		{
			for(int i=1;i<=26;++i)
			{
				if(cnt[i])
				{
					for(int j=1;j<=n;++j)	putchar('a'+i-1);
					break;
				}
			}
			puts("");
			continue;
		}
		else if(dt1)
		{
			for(int i=1;i<=26;++i)
			{
				if(cnt[i]==1)
				{
					putchar('a'+i-1);
					for(int j=1;j<=26;++j)
					{
						if(j==i)	continue;
						for(int k=1;k<=cnt[j];++k)	putchar('a'+j-1);
					}
					break;
				}
			}
			puts("");
		}
		else if(col==2)
		{
			int a=0,b=0;
			for(int i=1;i<=26;++i)	if(cnt[i])	{a=i;break;}
			for(int i=a+1;i<=26;++i)	if(cnt[i])	{b=i;break;}
			if(cnt[a]>cnt[b]+2)
			{
				putchar(trans(a));
				for(int i=1;i<=cnt[b];++i)	putchar(trans(b));
				for(int i=1;i<cnt[a];++i)	putchar(trans(a));
				puts("");
			}
			else
			{
				putchar(trans(a));
				putchar(trans(a));
				for(int i=1;i<=cnt[a]-2;++i)	putchar(trans(b)),putchar(trans(a));
				for(int i=cnt[b];i>=cnt[a]-1;--i)	putchar(trans(b));
				puts("");
			}
		}
		else
		{
			int a=0,b=0,c=0;
			for(int i=1;i<=26;++i)	if(cnt[i])	{a=i;break;}
			for(int i=a+1;i<=26;++i)	if(cnt[i])	{b=i;break;}
			for(int i=b+1;i<=26;++i)	if(cnt[i])	{c=i;break;}
			if(cnt[a]*2>n+2)
			{
				putchar(trans(a)),putchar(trans(b));
				for(int i=1;i<cnt[a];++i)	putchar(trans(a));
				putchar(trans(c));
				--cnt[b],--cnt[c];
				for(int i=a+1;i<=26;++i)	for(int j=1;j<=cnt[i];++j)	putchar(trans(i));
				puts("");
			}
			else
			{
				putchar(trans(a)),putchar(trans(a)),putchar(trans(b));
				cnt[a]-=2,cnt[b]--;
				int pos=b;
				while(cnt[a])
				{
					putchar(trans(a));
					--cnt[a];
					while(!cnt[pos] && pos<=26)
					{
						++pos;
						if(pos>26)	break;
					}
					if(pos<=26)	putchar(trans(pos)),--cnt[pos];
				}
				for(int i=a+1;i<=26;++i)	for(int j=1;j<=cnt[i];++j)	putchar(trans(i));
				puts("");
			}
		}
	}
	return 0;
}