#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+10;
int a[maxn],f[maxn][4],c[maxn],las[maxn],l[maxn],r[maxn],t[maxn];
int main() {
	int n,T;
	scanf("%d",&T);
	while(T--) {
		int ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			las[i]=t[i]=f[i][0]=f[i][1]=f[i][2]=0;
			scanf("%d",a+i);
			c[i]=a[i];
		}
		sort(c+1,c+n+1);
		int m=unique(c+1,c+n+1)-c-1;
		for(int i=1;i<=n;i++) {
			r[a[i]=lower_bound(c+1,c+m+1,a[i])-c]=i;
			t[a[i]]++;
		}
		for(int i=n;i>=1;i--)l[a[i]]=i;
		for(int i=1;i<=n;i++) {
			f[i][0]=f[las[a[i]]][0]+1;
			f[i][1]=max(f[las[a[i]]][1],max(f[las[a[i]-1]][2],f[las[a[i]-1]][0]))+1;
			if(i==r[a[i]])f[i][2]=f[l[a[i]]][1]+t[a[i]]-1;
			ans=max(max(ans,f[i][0]),max(f[i][1],f[i][2]));
			las[a[i]]=i;
		}
		printf("%d\n",n-ans);
	}
	return 0;
}