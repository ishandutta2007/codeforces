#include<cstdio>
#include<cstring>
#include<map>
using namespace std;

map<int,int> B;
int a[210000];

int main()
{
	int T;scanf("%d",&T);
	while(T--){
		int n,K;bool pd=false;scanf("%d%d",&n,&K);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(B[a[i]-K]>0||B[a[i]+K]>0) pd=true;
			B[a[i]]=1;
		}
		for(int i=1;i<=n;i++) B[a[i]]=0;
		if(pd) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}