#include<bits/stdc++.h>
using namespace std;
int a[510],p[250010],cnt;
int cmp(int x,int y) {
	return a[x]<a[y];
}
void opt(int x) {
	p[++cnt]=x;
	swap(a[x+1],a[x+2]);
	swap(a[x],a[x+1]);
}
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		cnt=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		for(int i=1;i<=n-2;i++) {
			int now=-1,Min=1e9;
			for(int j=i;j<=n;j++)
				if(a[j]<Min)Min=a[now=j];
			while(now-2>=i)opt(now-2),now-=2;
			if(now>i)opt(now-1),opt(now-1);
		}
		if(a[n-1]>a[n]) {
			int FL=0;
			for(int i=n-2;i>=1;i--) {
				opt(i);
				int fl=1;
				for(int j=1;j<n;j++)
					if(a[j]>a[j+1])fl=0;
				FL|=fl;
				if(fl)break;
			}
			if(!FL) {
				puts("-1");
				continue;
			}
		}
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++)
			printf("%d ",p[i]);
		puts("");
	}
	return 0;
}