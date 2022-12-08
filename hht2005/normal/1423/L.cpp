#include<bits/stdc++.h>
using namespace std;
int a[1010],c[1010],w[1010],p[40],in[40],cnt;
bitset<1010>b[1010],f;
int main() {
	int n,s,d,k,v;
	scanf("%d%d%d",&n,&s,&d);
	for(int i=1;i<=s;i++) {
		scanf("%d",&k);
		while(k--) {
			scanf("%d",&v);
			a[v]|=1<<i;
		}
	}
	for(int i=1;i<=n;i++)
		b[i][i]=1;
	for(int i=1,las=1;i<=s&&i<=n;i++) {
		int j=-1;
		for(int k=las;k<=n&&!~j;k++)
			if(a[k]>>i&1)j=k;
		if(j==-1)continue;
		swap(a[las],a[j]);
		swap(b[las],b[j]);
		for(int k=1;k<=n;k++)
			if(k!=las&&(a[k]>>i&1)) {
				a[k]^=a[las];
				b[k]^=b[las];
			}
		las++;
	}
	for(int i=1;i<=n;i++) {
		int fl=0;
		for(int j=1;j<=s;j++) {
			if(a[i]>>j&1) {
				if(fl)p[++cnt]=j;
				fl=1;
			}
		}
	}
	sort(p+1,p+cnt+1);
	cnt=unique(p+1,p+cnt+1)-p-1;
	while(d--) {
		scanf("%d",&k);
		f.reset();
		for(int i=1;i<=k;i++) {
			scanf("%d",&v);
			f[v]=1;
		}
		memset(w,-1,sizeof(w));
		int ans=1e9,fl=1;
		for(int i=1;i<=n;i++) {
			c[i]=(f&b[i]).count()&1;
			if(c[i]&&!a[i])fl=0;//sdf
		}
		for(int i=0;i<1<<cnt;i++) {
			int sum=0;
			for(int j=1;j<=cnt;j++)
				sum+=(in[p[j]]=i>>(j-1)&1);
			for(int j=1;j<=s-cnt;j++) {
				int f=c[j];
				for(int k=1;k<=s;k++)
					if(in[k]&&(a[j]>>k&1))f^=1;
				sum+=f;
			}
			ans=min(ans,sum);
		}
		if(fl)printf("%d\n",ans);
		else puts("-1");
	}
	return 0;
}