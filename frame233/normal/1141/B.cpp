#include<cstdio>
const int N=200005;
int a[N<<1];
inline int max(int a,int b){return a>b?a:b;}
int main()
{
	int n,ans=0,len=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),a[i+n]=a[i];
	for(int i=1;i<=(n<<1);++i)
	{
		if(a[i])
		{
			++len;
			ans=max(ans,len);
		}
		else
		{
			len=0;
		}
	}
	printf("%d\n",ans);
	return 0;
}
//Dpair AK IOI