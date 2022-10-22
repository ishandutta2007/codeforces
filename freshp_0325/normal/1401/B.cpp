#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		int a,b,c,x,y,z;
		scanf("%d %d %d %d %d %d",&a,&b,&c,&x,&y,&z);
		int ans=min(c,y)*2;
		int tmp;
		tmp=min(c,y);
		c-=tmp,y-=tmp;
		if(c==0)
		{
			tmp=min(a,z);
			a-=tmp,z-=tmp;
			if(a==0)	ans-=2*z;
		}
		else
		{
			tmp=min(c,z);
			z-=tmp,c-=tmp;
			if(c==0)
			{
				tmp=min(a,z);
				z-=tmp,a-=tmp;
				if(a==0)	ans-=2*z;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}