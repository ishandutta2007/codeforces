#include<bits/stdc++.h>
#define ll long long
#define N 100010
#define maxi 100000
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
int t,ne[N],be[N],nm,num,n,a[N],la[N],su;
struct Info{int nu,we;}an[N];
int main(){
	read(t);
	for (int i=1,k=1,j=2;i<=maxi;i++){ne[i]=k;j--;if (j==0){k++;j=k+1;}}
	while (t--){
		read(n);num=0;su=0;
		for (int i=1;i<=n;i++)read(a[i]);
		for (int i=1;i<=n;i++)be[i]=0;
		while (num<n){
			nm=0;
			for (int i=1;i<=n;i++){
				if (be[i]==0){
					int l=0,r=nm,mid;
					while (l<r){mid=(l+r+1)/2;if (an[mid].nu>a[i])r=mid-1;else l=mid;}
					la[i]=an[l].we;
					if (l==nm){nm++;an[l+1].nu=a[i];an[l+1].we=i;}
					else{if (a[i]<an[l+1].nu){an[l+1].nu=a[i];an[l+1].we=i;}}
				}
			}
			if (nm<=ne[n-num]){
				for (int i=1;i<=n;i++) la[i]=0;
				for (int i=1;i<=nm;i++) an[i].nu=an[i].we=0;nm=0;num=n;
				for (int i=1;i<=n;i++){
					if (be[i]==0){
						int k=0;
						for (int j=1;j<=nm;j++)if (an[j].nu>a[i]&&(k==0||an[j].nu<an[k].nu))k=j;
						if (k==0){an[++nm].nu=a[i];an[nm].we=i;be[i]=++su;}
						else{be[i]=be[an[k].we];an[k].we=i;an[k].nu=a[i];}
					}
				}
			}else{
				int x=an[nm].we;su++;num+=nm;
				for (int i=1;i<=nm;i++,x=la[x])be[x]=su;
				for (int i=1;i<=n;i++) la[i]=0;
				for (int i=1;i<=nm;i++) an[i].nu=an[i].we=0;
			}
		}
		cout<<su<<'\n';
		for (int i=1;i<=su;i++){
			int sum=0;
			for (int j=1;j<=n;j++)if (be[j]==i)sum++;
			printf("%d ",sum);
			for (int j=1;j<=n;j++)if (be[j]==i)printf("%d ",a[j]);
			puts("");
		}
	}
	return 0;
}