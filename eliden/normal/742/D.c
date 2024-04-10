#include<stdio.h>
int n, m, maxW, p[2000], w[2000], b[2000], prev[2000], next[2000], gb[2000],gw[2000];
int root(int i)
{
    if(p[i]!=i)
	p[i] = root(p[i]);
    return p[i];
}
int main()
{
    scanf("%i%i%i",&n,&m,&maxW);
    for(int i=0;i<n;i++)
	scanf("%i",w+i);
    for(int i=0;i<n;i++)
	scanf("%i",b+i);
    int x, y;
    for(int i=0;i<n;i++)
	p[i]=i;
    for(int i=0;i<m;i++)
    {
	scanf("%i%i",&x,&y);
	x--;
	y--;
	p[root(x)]=root(y);
    }
    prev[0] = 0;
    for(int v=1;v<=maxW;v++)
	prev[v] = -1;
    for(int i=0;i<n;i++)
	if(p[i]==i)
	{
	    int k = 0;
	    for(int j=0;j<n;j++)
		if(root(j)==i)
		{
		    gb[k]=b[j];
		    gw[k]=w[j];
		    k++;
		}

	    /* for(int j=0;j<k;j++) */
	    /* 	printf("%i ",gb[j]); */
	    /* printf("\n"); */
	    
	    for(int v=0;v<=maxW;v++)
		next[v]=prev[v];
	    for(int v=0;v<maxW;v++)
		if(prev[v]>=0)
		    for(int j=0;j<k;j++)
		    {
			int y = gw[j]+v;
			int s = gb[j]+prev[v];
			if(y<=maxW && s>next[y])
			    next[y] = s;
		    }
	    int tb = 0;
	    int tw = 0;
	    for(int j=0;j<k;j++)
	    {
		tb+=gb[j];
		tw+=gw[j];
	    }
	    for(int v=0;v<maxW;v++)
		if(prev[v]>=0 && v+tw<=maxW && prev[v]+tb>next[v+tw])
		    next[v+tw] = tb+prev[v];
	    
	    for(int v=0;v<=maxW;v++)
		prev[v] = next[v];
	}
    int max = 0;
    for(int v=0;v<=maxW;v++)
	if(prev[v]>max)
	    max = prev[v];
    printf("%i\n",max);
}