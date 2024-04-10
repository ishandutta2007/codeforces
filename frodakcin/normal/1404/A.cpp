#include <cstdio>

const int MN = 3e5+10;

int T, N, K, c1, c2;
char s[MN];

int main()
{
	scanf("%d", &T);
	for(int tc=1;tc<=T;++tc)
	{
		scanf("%d%d", &N, &K);
		scanf(" %s", s);
		c1=c2=0;
		bool ok=1;
		for(int i=N-K-1;ok&&i>=0;--i)
			if(s[i]=='?') s[i]=s[i+K];
			else if(s[i+K]=='?');
			else if(s[i]!=s[i+K]) ok=0;
		for(int i=0;i<K;++i)
			if(s[i]=='1') ++c1;
			else if(s[i]=='0')++c2;
		if(!ok || c1 > K/2 || c2 > K/2)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}