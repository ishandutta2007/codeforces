#include<bits/stdc++.h>

using namespace std;
 
int a[200005],len,n,k,q,i;

int main()
{
    scanf("%d",&q);
    while(q--)
	{
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++)
        {
        	int temp;
        	scanf("%d",&temp);
    		if(temp%2==1)
    		{
    			a[len]=i+1;
    			len++;
			}
		}
        if(len<k)
            printf("NO\n");
        else if(k%2==len%2)
		{
            printf("YES\n");
            for(i=0;i<k-1;i++)
            	printf("%d ",a[i]);
            printf("%d\n",n);
        }
		else
            printf("NO\n");
        for(i=0;i<n;i++)
        	a[i]=0;
        len=0;
    }
	return 0;
}