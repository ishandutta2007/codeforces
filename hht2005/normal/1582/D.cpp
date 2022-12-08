#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=10000;
int a[N],b[N],las[N],f[N],id[N];
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(int i=1;i<=n;i++)f[i]=0;
		for(int i=0;i<=20000;i++)las[i]=0;
		int sum=0;
		for(int i=1;i<=n;i++) {
			scanf("%d",a+i);
			if(las[abs(a[i])]&&sum+2+2<=n) {
				sum+=2;
				int I=las[abs(a[i])];
				b[i]=1;
				if(a[i]==a[I])b[I]=-1;
				else b[I]=1;
				f[i]=1;
				f[I]=1;
				las[abs(a[i])]=0;
			} else las[abs(a[i])]=i;
		}
		int m=0;
		for(int i=1;i<=n;i++)
			if(!f[i])id[++m]=i;
		for(int i=2;i<=m;i+=2) {
			b[id[i]]=a[id[i-1]];
			b[id[i-1]]=-a[id[i]];
		}
		if(m%2) {
			int x=id[m-2],y=id[m-1],z=id[m];
			if(a[y]+a[z]==0)swap(x,y);
			if(a[y]+a[z]==0)swap(x,z);
			b[x]=a[y]+a[z];
			b[y]=-a[x];
			b[z]=-a[x];
		}
		for(int i=1;i<=n;i++)
			printf("%d ",b[i]);
		puts("");
	}
	return 0;
}