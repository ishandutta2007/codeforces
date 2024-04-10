#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool cmp(int n1,int n2) {return (n1<n2);}
const int N=1e5+100;
int f[N],a[N],b[N],g[N],h[N];bool bk[N];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int m;scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	sort(b+1,b+m+1,cmp);
	memset(f,60,sizeof(f));f[0]=-1e9;
	for(int i=1;i<=n;i++){
		if(a[i]!=-1){
			int l=1,r=n,ans;
			while(l<=r){
				int mid=(l+r)>>1;
				if(f[mid]>=a[i]) ans=mid,r=mid-1;
				else l=mid+1;
			}
			if(i==88){
				i++;i--;
			}
			h[i]=g[ans-1];
			f[ans]=a[i];g[ans]=i;
		}
		else{
			int id=n;
			for(int j=m;j>=1;j--){
				while(f[id-1]>=b[j]) id--;
				if(h[i]==0) h[i]=g[id-1];
				f[id]=b[j];g[id]=g[id-1];
			}
		}
		while(a[h[i]]==-1) h[i]=h[h[i]];
	}
	memset(bk,true,sizeof(bk));
	int pd;
	for(int i=n;i>=1;i--)
		if(f[i]<=1e9) {pd=i;break;}
	int t=g[pd],id=m,las=2e9;
	for(int i=n;i>=t;i--){
		if(a[i]==-1){
			while(b[id]>=las) id--;
			if(id==0) continue;
			a[i]=b[id];las=b[id];bk[id]=false;
		}
	}
	while(t){
		las=a[t];
		if(las==-1) las=2e9;
		for(int i=t;i>=h[t];i--){
			if(a[i]==-1){
				while(b[id]>=las) id--;
				if(b[id]<=a[h[t]]) continue;
				a[i]=b[id];las=b[id];bk[id]=false;
			}
		}
		t=h[t];
	}
	id=1;
	for(int i=1;i<=n;i++){
		if(a[i]==-1){
			while(!bk[id]) id++;
			a[i]=b[id];id++;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d",a[i]);
		if(i<n) printf(" ");
		else printf("\n");
	}
	return 0;
}