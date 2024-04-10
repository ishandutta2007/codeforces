#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	long n,p1,p2,p3,t1,t2,l,r,last=-1,ans=0;
	scanf("%d%d%d%d%d%d",&n,&p1,&p2,&p3,&t1,&t2);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&l,&r);
		if (last!=-1)
		{
			if (l-last<=t1)
			{
				ans+=p1*(l-last);
			}
			else
			{
				if (l-last<=t1+t2)
				{
					ans+=p1*t1+p2*(l-last-t1);
				}
				else
				{
					ans+=p1*t1+p2*t2+p3*(l-last-t1-t2);
				}
			}
		}
		ans+=p1*(r-l);
		last=r;
	}
	printf("%d\n",ans);
	return 0;
}