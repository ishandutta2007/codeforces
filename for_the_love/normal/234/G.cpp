#include <cstdio>
#include <cstring>

int lg(int n)
{
	if(n==1) return 0;
	return lg(n+1>>1)+1;
}

int main()
{
        int n,res,i,j,c;
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);

	scanf("%d",&n);
        res = lg(n);
	printf("%d\n",res);
	for(i=0;i<res;i++)
	{
		c=0;
		for(j=0;j<n;j++)
			if(j>>i&1) c++;
		printf("%d ",c);
		for(j=0;j<n;j++)
			if(j>>i&1) printf("%d ",j+1);
		puts("");
	}
}