#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+100;
int a[N];
bool cmp(int n1,int n2) {return (n1<n2);}
int main()
{
	int T;scanf("%d",&T);
	while(T--){
		int n,k;scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1,cmp);
		int mex=0,max=0;
		for(int i=1;i<=n;i++){
			if(a[i]==mex) mex++;
			if(max<a[i]) max=a[i];
		}
		int Sum=1;
		for(int i=2;i<=n;i++)
			if(a[i]!=a[i-1]) Sum++;
		if(k==0){
			printf("%d\n",Sum);
			continue;
		}
		int t=(max+mex+1)/2;
		bool pd=false;
		for(int i=1;i<=n;i++)
			if(a[i]==t) {pd=true;break;}
		if(pd) printf("%d\n",Sum);
		else{
			if(t!=mex) printf("%d\n",Sum+1);
			else printf("%d\n",Sum+k);
		}
	}
	return 0;
}