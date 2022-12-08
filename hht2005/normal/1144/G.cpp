#include<bits/stdc++.h>
using namespace std;
int a[200010],ans1[200010],ans2[200010],ans[200010];
int main() {
	int n,f1=0,f2=0,t1,t2;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		t1=-1,t2=-1;
		if((i==1||a[i-1]<a[i])&&~f1)t1=f1,ans1[i]=i-1;
		if(~f2&&(!f2||a[f2]<a[i])&&(!~t1||a[t1]<a[i-1]&&t1))t1=i-1,ans1[i]=f2;
		if((i==1||a[i-1]>a[i])&&~f2)t2=f2,ans2[i]=i-1;
		if(~f1&&(!f1||a[f1]>a[i])&&(!~t2||a[t2]>a[i-1]&&t2))t2=i-1,ans2[i]=f1;
		f1=t1,f2=t2;
	}
	if(~f1||~f2)puts("YES");
	else puts("NO");
	if(~f1) {
		int x=n;
		while(x)ans[x]=1,x=ans1[x];
		for(int i=1;i<=n;i++)printf("%d ",ans[i]^1);
		puts("");
	} else if(~f2) {
		int x=n;
		while(x)ans[x]=1,x=ans2[x];
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}