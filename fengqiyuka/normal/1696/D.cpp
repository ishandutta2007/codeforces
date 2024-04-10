#include<bits/stdc++.h>
using namespace std;

const int N=250010;
int a[N],sta1[N],sta2[N],f[N];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		
		int tot1=1,tot2=1;sta1[1]=sta2[1]=1;
		for(int i=2;i<=n;i++){
			if(a[i]>a[i-1]){
				while(tot1&&a[sta1[tot1]]<a[i]) tot1--;
				int las=sta1[tot1];sta1[++tot1]=i;
				int l=1,r=tot2,ans;
				while(l<=r){
					int mid=(l+r)>>1;
					if(sta2[mid]>las) ans=mid,r=mid-1;
					else l=mid+1;
				}
				f[i]=f[sta2[ans]]+1;
			}
			else{
				while(tot2&&a[sta2[tot2]]>a[i]) tot2--;
				int las=sta2[tot2];sta2[++tot2]=i;
				int l=1,r=tot1,ans;
				while(l<=r){
					int mid=(l+r)>>1;
					if(sta1[mid]>las) ans=mid,r=mid-1;
					else l=mid+1;
				}
				f[i]=f[sta1[ans]]+1;
			}
		}
		
		printf("%d\n",f[n]);
	}
	
	return 0;
}