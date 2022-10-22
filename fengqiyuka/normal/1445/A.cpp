#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=110;
int a[N],b[N];
bool cmp(int n1,int n2) {return (n1<n2);}
int main()
{
	int T;scanf("%d",&T);
	while(T--){
		int n,X;
		scanf("%d%d",&n,&X);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		bool pd=true;
		for(int i=1;i<=n;i++)
			if(a[i]+b[n-i+1]>X)
				{pd=false;break;}
		if(pd) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}