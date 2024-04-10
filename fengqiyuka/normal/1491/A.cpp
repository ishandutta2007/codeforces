#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e5+100;
int a[N];
int main()
{
	int n,q,sum=0;scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
	for(int i=1;i<=q;i++){
		int ty;scanf("%d",&ty);
		if(ty==1){
			int x;scanf("%d",&x);
			if(a[x]==1) sum--;
			else sum++;
			a[x]=1-a[x];
		}
		else{
			int x;
			scanf("%d",&x);
			if(x<=sum) printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}