#include <cstdio>
#include <vector>

const int MN = 1e6+10;

int N, a[MN], nx[2], jmp[MN];
char s[MN];
std::vector<int> u[MN];

int find(int x)
{
	if(jmp[x]==x) return x;
	return jmp[x]=find(jmp[x]);
}

int main()
{
	scanf("%d %s", &N, s);
	nx[0]=nx[1]=N;
	jmp[N]=N;
	for(int i=N-1;i>=0;--i)
	{
		if(s[i]!='?') nx[s[i]=='1']=i;
		a[i]=std::max(nx[0], nx[1])-i;
		u[a[i]].push_back(i);
		jmp[i]=i;
	}
	for(int i=1,f;i<=N;++i)
	{
		f=0;
		for(int j=0;;j+=i)
		{
			j=find(j);
			if(j==N) break;
			++f;
		}
		printf("%d%c", f, " \n"[i==N]);
		for(int x:u[i])
			jmp[x]=find(jmp[x+1]);
	}
	return 0;
}