#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[1000005],last,ans,b[1000005];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
	for (int i=2;i<n;i++)
		if (a[i]!=a[i-1]&&a[i]!=a[i+1]){
			if (last) ans=max(ans,(i-last+1+1)/2);
			else{last=i;ans=max(ans,1);}
			if (i==n-1||(!(a[i+1]!=a[i]&&a[i+1]!=a[i+2]))){
				int len=i-last;
				for (int j=last;j<=last+len/2;j++) b[j]=a[last-1];
				for (int j=last+len/2+1;j<=i;j++) b[j]=a[i+1];
			}
		}
		else last=0;
	printf("%d\n",ans);
	for (int i=1;i<n;i++) printf("%d ",b[i]);printf("%d",b[n]);
}