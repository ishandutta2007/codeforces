#include <cstdio>
#include <algorithm>

const int MN = 1e6+10;

int N;

char s[MN];
int z[MN], L=-1;
int maxl;
bool ok[MN];

int main()
{
	scanf(" %s", s);
	for(;s[N];++N);
	z[0]=0;
	for(int i=1,m=-1,r=-1;i<N;++i)
	{
		z[i]=i<r?std::min(r-i, z[i-m]):0;
		for(;i+z[i]<N && s[z[i]]==s[i+z[i]];)++z[i];
		if(i+z[i]>r) r=i+z[i], m=i;
	}
	//for(int i=0;i<N;++i) printf("%d: %3d\n", i, z[i]);

	for(int i=1;i<N;++i)
	{
		if(i+z[i]==N) ok[z[i]]=1;

		if(i+z[i]==N)--z[i];
		maxl=std::max(maxl, z[i]);
	}
	//printf("%d\n", maxl);

	for(int i=1;i<=maxl;++i)
		if(ok[i])
			L=i;
	if(~L)
	{
		s[L]=0;
		printf("%s\n", s);
	}
	else
		printf("Just a legend\n");
	return 0;
}