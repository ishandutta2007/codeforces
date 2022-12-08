#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn],x[maxn],y[maxn],sk[maxn],top,cnt;
int main() {
	int n,P,ly=-1,fl=0;
	scanf("%d",&n),P=n;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=n;i>=1;i--) {
		if(a[i]==1) {
			sk[++top]=x[++cnt]=P--;
			y[cnt]=i;
			if(!fl)ly=i;
		} else if(a[i]==2) {
			if(top<=0)return puts("-1"),0;
			x[++cnt]=sk[top--];
			y[cnt]=i;
			ly=i,fl=1;
			P=min(P,x[cnt]-1);
		} else if(a[i]==3) {
			if(ly==-1)return puts("-1"),0;
			x[++cnt]=P;
			y[cnt]=ly;
			x[++cnt]=P;
			y[cnt]=ly=i;
			if(!fl)top--;
			fl=1;
			P--;
		}
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
		printf("%d %d\n",x[i],y[i]);
	return 0;
}