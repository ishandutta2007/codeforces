#include<cstdio>

const char iname[]="input.txt";
const char oname[]="output.txt";

char s[250];

int n,i,dis,last;

int main()
{
	freopen(iname,"r",stdin);
	freopen(oname,"w",stdout);
	scanf("%d\n",&n);
    fgets(s+1,sizeof(s),stdin);
	i=1;
	dis=-1;
	last=n+1;
	while(s[i]=='0')
		++i;
	while(i<=n)
	{
		if(dis>-1&&i-last!=dis)
			break;
		else
			dis=i-last;
		last=i;
		++i;
		while(s[i]=='0'&&i<=n)
			++i;
	}
	if(i<=n)
		printf("NO\n");
	else
		printf("YES\n");
}