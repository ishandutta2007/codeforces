#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],x[N],y[N],z[N],n,m;
int X[N],Y[N],Z[N],S[1<<12];
void opt(int X,int Y,int Z) {
	x[++m]=X;
	y[m]=Y;
	z[m]=Z;
	a[X]^=1;
	a[Y]^=1;
	a[Z]^=1;
}
void bf(int l,int r) {
	while(r-l+1<8&&l>1)l--;
	while(r-l+1<8&&r<n)r++;
	int sum=0;
	for(int i=0;i<8;i++)
		if(l+i<=r)sum|=a[l+i]<<i;
	for(int i=0;i<1<<12;i++)
		if((sum^S[i])==0) {
			int FL=1;
			for(int j=0;j<12;j++)
				if((i>>j&1)&&Z[j]+l>r)FL=0;
			if(!FL)continue;
			for(int j=0;j<12;j++)
				if(i>>j&1)opt(X[j]+l,Y[j]+l,Z[j]+l);
			return;
		}
	puts("NO");
	exit(0);
}
void solve(int l,int r) {
	while(a[l]==0&&l<=r)l++;
	while(a[r]==0&&l<=r)r--;
	if(l>r)return;
	if(r-l+1<=8) {
		bf(l,r);
		return;
	}
	if(a[l+1]==1&&a[l+2]==1)opt(l,l+1,l+2);
	else if(a[l+1]==0&&a[l+2]==0)opt(l,l+3,l+6);
	else if(a[l+1]==0&&a[l+2]==1)opt(l,l+2,l+4);
	else {
		if(a[r-1]==1&&a[r-2]==1)opt(r-2,r-1,r);
		else if(a[r-1]==0&&a[r-2]==0)opt(r-6,r-3,r);
		else if(a[r-1]==0&&a[r-2]==1)opt(r-4,r-2,r);
		else {
			if((l+r)%2) {
				opt(l,(l+r-1)/2,r-1);
				opt(l+1,(l+r+1)/2,r);
			} else {
				opt(l,(l+r)/2,r);
				opt(l+1,(l+r)/2,r-1);
			}
			solve(l+3,r-3);
			return;
		}
		solve(l,r-3);
		return;
	}
	solve(l+3,r);
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	int m=0;
	for(int i=0;i<8;i++)
		for(int j=1;i+j+j<8;j++)
			X[m]=i,Y[m]=i+j,Z[m++]=i+2*j;
	for(int i=0;i<1<<12;i++)
		for(int j=0;j<12;j++)
			if(i>>j&1)S[i]^=(1<<X[j])^(1<<Y[j])^(1<<Z[j]);
	solve(1,n);
	puts("YES");
	printf("%d\n",::m);
	for(int i=1;i<=::m;i++)
		printf("%d %d %d\n",x[i],y[i],z[i]);
	return 0;
}