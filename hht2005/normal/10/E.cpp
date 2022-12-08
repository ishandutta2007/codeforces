#include<bits/stdc++.h>
using namespace std;
const int N=410;
int a[N],f[N],t[N],n;
int calc(int x) {
	int cnt=0;
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++) {
		f[i]=x/a[i];
		cnt+=f[i];
		x%=a[i];
	}
	return cnt;
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	int ans=1.1e9;
	for(int i=n-1;i>1;i--) {
		calc(a[i-1]-1);
		memcpy(t,f,sizeof(t));
		for(int j=i;j<=n;j++) {
			int w=0,sum=0;
			for(int k=1;k<j;k++)
				w+=t[k]*a[k],sum+=t[k];
			sum+=t[j]+1;
			w+=t[j]*a[j]+a[j];
			if(calc(w)>sum)ans=min(ans,w);
		}
	}
	if(ans>1e9)puts("-1");
	else printf("%d\n",ans);
	return 0;
}