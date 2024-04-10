#include<cstdio>
#include<cstring>
using namespace std;
const int N=110;
int a[N];
int mymin(int x,int y) {return x<y?x:y;}
int main()
{
	int T;scanf("%d",&T);
	while(T--){
		int n,A,B;bool pd=false,pd2=false;
		scanf("%d%d%d",&n,&A,&B);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(i>1&&a[i]!=a[i-1]) pd=true;
			if(i>1&&(a[i]<a[i-1]-1||a[i]>a[i-1]+1)) pd2=true;
		}
		if(pd2){
			printf("0\n");
			continue;
		}
		if(pd) printf("%d\n",mymin(A,B));
		else printf("%d\n",B+mymin(A,B));
	}
	return 0;
}