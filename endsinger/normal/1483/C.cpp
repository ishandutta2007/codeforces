#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,h[300004],a[300004],t;
ll f[300004];
int st[300004];
ll pre[300004];
ll d[300004];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&h[i]);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	f[0]=0;
	for(int i=1;i<=n;i++){
		ll tmp=f[i-1];
		while(t>0&&h[st[t-1]]>h[i])t--,tmp=max(tmp,d[t]);
		t++;
		d[t-1]=tmp;
		st[t-1]=i;
		pre[t-1]=tmp+a[i];
		if(t>1)pre[t-1]=max(pre[t-1],pre[t-2]);
		f[i]=pre[t-1];
	}
	printf("%I64d",f[n]);
}