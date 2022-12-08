#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int p[N],c[N],H[N],cnt;
int a[N],b[N],m;
void Swap(int x,int y) {
	swap(p[x],p[y]);
	a[++m]=x,b[m]=y;
}
void opt(int A,int B) {
	Swap(A,B);
	while(p[A]!=B)Swap(A,p[A]);
	while(p[B]!=A)Swap(B,p[B]);
	Swap(A,B);
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",p+i);
	for(int i=1;i<=n;i++) {
		if(c[i])continue;
		c[H[++cnt]=i]=1;
		for(int j=p[i];j!=i;j=p[j])c[j]=1;
	}
	if(cnt>1) {
		for(int i=2;i<=cnt;i+=2)opt(H[i-1],H[i]);
		if(cnt&1)opt(H[1],H[cnt]);
	} else {
		int c=H[1],a=p[c];
		Swap(a,c);
		while(p[p[c]]!=c)Swap(c,p[c]);
		int b=p[c];
		Swap(a,b);
		Swap(b,c);
		Swap(a,c);
	}
	printf("%d\n",m);
	for(int i=1;i<=m;i++)
		printf("%d %d\n",a[i],b[i]);
	return 0;
}