#include<bits/stdc++.h>
using namespace std;
int n,st[1000005],top;
double a[1000005],ans[1000005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lf",&a[i]),a[i]+=a[i-1];
	st[++top]=0;
	for(int i=1;i<=n;i++){
		while(top>1&&(a[i]-a[st[top]])/(i-st[top])<(a[st[top]]-a[st[top-1]])/(st[top]-st[top-1]))top--;
		st[++top]=i;
	}
	for(int i=1;i<=top;i++){
		double s=a[st[i]]-a[st[i-1]];
		for(int j=st[i-1]+1;j<=st[i];j++)ans[j]=s/(st[i]-st[i-1]);
	}
	for(int i=1;i<=n;i++)printf("%.10lf\n",ans[i]);
}