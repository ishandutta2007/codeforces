#include<stdio.h>
const int sz = 2000002;
int bit[sz], n, k;
void add(int i)
{
    while(i<sz)
    {
	bit[i]++;
	i+=i&(-i);
    }
}
int get(int i)
{
    int x = 0;
    while(i>0)
    {
	x+=bit[i];
	i-=i&(-i);
    }
    return x;
}
int insert(int i)
{
    add(i);
    add(i+n);
    // add(i+2*n);
}
int query(int l,int r)
{
    l%=n;
    r%=n;
    if(l>r)
	l-=n;
    // printf("%i to %i: %i\n",l,r,get(n+r)-get(n+l-1));
    return get(n+r)-get(n+l-1);
}
int main()
{
    scanf("%i%i",&n,&k);
    for(int i=0;i<sz;i++)
	bit[i] = 0;
    if(2*k>n)
	k = n-k;
    
    long long s = 1, i=1;
    bool flag = false;
    while(!flag || i!=1)
    {
	// printf("%i\n",i);
	s+=1+query(i-k+1,i+k-1);
	printf("%lli ",s);
	insert(i);
	
	i = (i+k)%n;
	if(i==0)
	    i=n;
	flag = true;
    }
    printf("\n");
}