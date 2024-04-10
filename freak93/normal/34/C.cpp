#include<cstdio>
#include<cstring>

using namespace std;

const char iname[]="c.in";
const char oname[]="c.out";

int start,i,k,v[1005],a[1005],afis;
char c;

int main()
{
	//freopen(iname,"r",stdin);
	//freopen(oname,"w",stdout);
    scanf("%d",&a[1]);
	k=1;
	do
	{
		c=0;
		scanf("%c",&c);
		if(c!=',')
			break;
		++k;
		scanf("%d",&a[k]);
	}while(1);
	for(i=1;i<=k;++i)
		v[a[i]]=1;
	for(i=1;i<=1000;++i)
		if(v[i]==1)
		{
			start=i;
			while(v[i+1]==1)
				++i;
			if(afis)
				printf(",");
			afis=1;
			if(start!=i)
				printf("%d-%d",start,i);
			else
				printf("%d",i);
		}
}