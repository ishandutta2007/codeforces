#include<bits/stdc++.h>
using namespace std;
const int N=1<<12;
int a[N],p[N],f1[N],f2[N];
int main() {
	int k;
	scanf("%d",&k);
	int n=1<<k,sum=n,X=0;
	for(int i=0;i<n;i++)
		scanf("%d",a+i),X^=a[i];
	if(X)puts("Fou"),exit(0);
	memset(p,-1,sizeof(p));
	while(sum) {
		int t=rand()%sum+1;
		int x=0,c1=0,I=0;
		for(int i=0;i<n;i++)
			if(!f1[i]) {
				c1++;
				if(c1==t)x=i;
			}
		f1[x]=1;
		c1=0;
		for(int i=0;i<n;i++)
			if(!~p[i]&&!f2[a[i]^x])
				c1++;
		if(c1) {
			t=rand()%c1+1;
			c1=0;
			for(int i=0;i<n;i++)
				if(!~p[i]&&!f2[a[i]^x]) {
					c1++;
					if(c1==t)I=i;
				}
			p[I]=x;
			f2[a[I]^p[I]]=1;
			sum--;
		} else {
			c1=0;
			for(int i=0;i<n;i++)
				if(!~p[i])c1++;
			t=rand()%c1+1;
			c1=0;
			for(int i=0;i<n;i++)
				if(!~p[i]) {
					c1++;
					if(c1==t)I=i;
				}
			for(int i=0;i<n;i++)
				if(~p[i]&&(p[i]^a[i])==(x^a[I])) {
					f1[p[i]]=f2[p[i]^a[i]]=0;
					p[i]=-1;
				}
			p[I]=x;
			f1[p[I]]=f2[a[I]^p[I]]=1;
		}
	}
	puts("Shi");
	for(int i=0;i<n;i++)printf("%d ",p[i]);puts("");
	for(int i=0;i<n;i++)printf("%d ",p[i]^a[i]);puts("");
	return 0;
}