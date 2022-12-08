#include<stdio.h>
int n, k, x, cut, cnt;
int main()
{
    scanf("%i%i",&n,&k);
    cnt = 0;
    for(int i=1;i<=n;i++)
    {
	scanf("%i",&x);
	if(x>0 && (i<=k || x==cut))
	    cnt++;
	if(i==k)
	    cut = x;
    }
    printf("%i\n",cnt);
}