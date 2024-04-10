#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e5+100;
int a[N],d[N],L[N];
int main()
{
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);d[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]>0){
				L[i]=i-a[i]+1;
				if(L[i]<1) L[i]=1;
				while(d[0]&&L[d[d[0]]]>=L[i]) d[0]--;
				d[++d[0]]=i;
			}
		}
		int t=1;
		for(int i=1;i<=d[0];i++){
			if(L[d[i]]>t){
				for(int j=t;j<L[d[i]];j++) printf("0 ");
				for(int j=L[d[i]];j<=d[i];j++) printf("1 ");
				t=d[i]+1;
			}
			else{
				for(int j=t;j<=d[i];j++) printf("1 ");
				t=d[i]+1;
			}
		}
		for(int i=t;i<=n;i++) printf("0 ");
		printf("\n");
	}
	return 0;
}