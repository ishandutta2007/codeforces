#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char c;
int x1,y1,x2,y2,i,j,rez;

int main()
{
	scanf("%c%d\n",&c,&y1);
	x1=c-'a'+1;
	scanf("%c%d",&c,&y2);
	x2=c-'a'+1;
	for(i=1;i<=8;++i)
		for(j=1;j<=8;++j)
			if((i!=x1||j!=y1)&&(i!=x2||j!=y2))
				if((i!=x1)&&(j!=y1))
					if((max(i-x1,x1-i)!=2||max(j-y1,y1-j)!=1)&&((max(i-x1,x1-i)!=1||max(j-y1,y1-j)!=2)))
						if((max(i-x2,x2-i)!=2||max(j-y2,y2-j)!=1)&&((max(i-x2,x2-i)!=1||max(j-y2,y2-j)!=2)))
							++rez;
	printf("%d",rez);
}