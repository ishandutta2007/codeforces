#include<bits/stdc++.h>
using namespace std;
const int maxn=8010;
int a[maxn];
bitset<maxn>f,t;
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		f.reset();
		t.reset();
		int ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		for(int j=2;j<=n;j++) {
			t[a[j-1]]=1;
			t<<=a[j];
			f|=t;
		}
		for(int i=1;i<=n;i++)
			if(f[a[i]])ans++;
		printf("%d\n",ans);
	}
	return 0;
}