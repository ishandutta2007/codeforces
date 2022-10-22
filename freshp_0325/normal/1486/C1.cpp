#include<bits/stdc++.h>
using namespace std;
#define F fflush(stdout)
int n;
int main(){
	scanf("%d",&n);
	int p;
	printf("? 1 %d\n",n);
	F;
	scanf("%d",&p);
	int l=1,r=n;
	if(p==1)
	{
		l=2;
	}
	else
	{
		int dk;
		printf("? %d %d\n",1,p);
		F;
		scanf("%d",&dk);
		if(dk==p)	r=p-1;
		else	l=p+1;
	}
	if(l==p+1)
	{
		while(l<r)
		{
			int mid=(l+r)>>1;
			printf("? %d %d\n",p,mid);
			F;
			int sp;
			scanf("%d",&sp);
			if(sp==p)	r=mid;
			else	l=mid+1;
		}
	}
	else
	{
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			printf("? %d %d\n",mid,p);
			F;
			int sp;
			scanf("%d",&sp);
			if(sp==p)	l=mid;
			else	r=mid-1;
		}
	}
	printf("! %d",l);
	F;
	return 0;
}
/*
6 1 2 3 4 5
*/