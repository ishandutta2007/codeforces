#include<cstdio>
int main()
{
	int n,x,y,t,ans=0;
	scanf("%d %d %d",&n,&x,&y);
	if(x>y) return printf("%d\n",n),0;
	for(int i=1;i<=n;i++) scanf("%d",&t),ans+=t<=x;
	printf("%d\n",(ans>>1)+(ans&1));
	return 0;
}