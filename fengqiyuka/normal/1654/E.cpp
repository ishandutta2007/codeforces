#include<cstdio>
#include<cstring>
#include<map>
using namespace std;

const int N=1e5+100,maxn=1e5,o=340,maxn2=35000000;
int a[N],b[2*N],g[70000000];

int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	int Ans=1;
	for(int i=-o;i<=o;i++){
		for(int j=1;j<=n;j++){
			g[a[j]-j*i+maxn2]++;
			int t=g[a[j]-j*i+maxn2];
			if(Ans<t) Ans=t;
		}
		for(int j=1;j<=n;j++) g[a[j]-j*i+maxn2]--;
	}

	for(int i=1;i<n;i++){
		for(int j=i+1;j<=i+o&&j<=n;j++){
			if((a[j]-a[i])%(j-i)==0){
				b[(a[j]-a[i])/(j-i)+maxn]++;
				int t=b[(a[j]-a[i])/(j-i)+maxn];
				if(Ans<t+1) Ans=t+1;
			}
		}
		for(int j=i+1;j<=i+o&&j<=n;j++){
			if((a[j]-a[i])%(j-i)==0){
				b[(a[j]-a[i])/(j-i)+maxn]--;
			}
		}
	}
	
	printf("%d\n",n-Ans);
	
	return 0;
}