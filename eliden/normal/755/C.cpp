#include<stdio.h>
const int sz = 100000;
int p[sz], n;
int root(int i)
{
    if(p[i]!=i)
	p[i] = root(p[i]);
    return p[i];
}
int main()
{
    scanf("%i",&n);
    for(int i=0;i<n;i++)
	p[i] = i;
    int o;
    for(int i=0;i<n;i++)
    {
	scanf("%i",&o);
	o--;
	p[root(i)]=root(o);
    }
    bool marked[sz];
    for(int i=0;i<n;i++)
	marked[i] = false;
    int count = 0;
    for(int i=0;i<n;i++)
	if(!marked[root(i)])
	{
	    marked[root(i)] = true;
	    count++;
	}
    printf("%i\n",count);
}