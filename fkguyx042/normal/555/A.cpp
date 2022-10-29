#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100005],n,k,i,j,x;
int main()
{
scanf("%d%d",&n,&k);
int ans=n-2;
for (i=1;i<=k;++i)
{   
        scanf("%d",&x); ans+=x-1;
		for (j=1;j<=x;++j) scanf("%d",&a[j]);
		for (j=1;j<=x;++j)
		 if(a[j]==1){
			int R=j;
			while(R<x&&a[R+1]==a[R]+1) ++R,ans-=2;
		    R=j;
			while(R>1&&a[R-1]==a[R]+1){
				ans-=2;R--;
			}
		}
	}
	printf("%d\n",++ans);
}