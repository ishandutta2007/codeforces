#include<stdio.h>
#include<stdbool.h>
char a[200];
int n, k;
int main()
{
    scanf("%i%i%s",&n,&k,a);
    int g, t;
    for(int i=0;i<n;i++)
	if(a[i]=='G')
	    g = i;
	else if(a[i]=='T')
	    t = i;
    bool good;
    if((g-t)%k==0)
    {
	if(g<t)
	{
	    good = true;
	    for(int i=g;i<t;i+=k)
		if(a[i]=='#')
		    good = false;
	}
	else
	{
	    good = true;
	    for(int i=t;i<g;i+=k)
		if(a[i]=='#')
		    good = false;
	}
	    
    }
    else
	good = false;
    if(good)
	printf("YES\n");
    else
	printf("NO\n");
}