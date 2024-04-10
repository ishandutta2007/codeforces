#include<stdio.h>
const int sz = 1000000;
int n, a[sz];
int main()
{
    scanf("%i",&n);

    for(int i=0;i<n;i++)
    {
	scanf("%i",&a[i]);
	a[i]--;
    }
    int parity = 1;
    for(int i=0;i<n;i++)
    {
	int x;
	scanf("%i",&x);
	parity^=x;
    }
    bool vis[sz];
    for(int i=0;i<n;i++)
	vis[i] = false;
    int cyc = 0;
    for(int i=0;i<n;i++)
	if(!vis[i])
	{
	    cyc++;
	    int j = i;
	    while(!vis[j])
	    {
		vis[j] = true;
		j = a[j];
	    }
	}

    if(cyc==1)
	printf("%i\n",parity);
    else
	printf("%i\n",cyc+parity);
}