#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
int a[maxn];
int main() {
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	int n,x,T;
	scanf("%d",&T);
	while(T--) {
		int cnt=0;
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		for(int i=1;i<=n;i++) {
			if(a[i]>x) {
				int fl=1;
				for(int j=i;j<n&&fl;j++)
					if(a[j]>a[j+1])fl=0;
				if(fl)break;
				swap(a[i],x);
				cnt++;
			}
		}
		int fl=1;
		for(int i=1;i<n&&fl;i++)
			if(a[i]>a[i+1])fl=0;
		if(!fl)puts("-1");
		else printf("%d\n",cnt);
	}
	return 0;
}