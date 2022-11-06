#include<bits/stdc++.h>
#define ll long long
#define N 210
using namespace std;
template <typename T> void read(T &x){
	x=0;char ch=getchar();int fh=1;
	while (ch<'0'||ch>'9'){if (ch=='-')fh=-1;ch=getchar();}
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
int m,n,a[N][N],b[N][N];
bool pa(int x){
	for (int i=1;i<=m;i++)if (b[x][1]!=b[x][i])return 0;
	return 1;
}
bool pa1(int x){
	int l=1,r=m;
	while (l+1<=m&&b[x][l]==b[x][1])l++;
	while (r-1>=1&&b[x][r]==b[x][m])r--;
	return (l>r);
}
bool check1(){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)b[i][j]=a[i][j];
	for (int i=1;i<=m;i++)
		if (b[1][i])
			for (int j=1;j<=n;j++)b[j][i]^=1;
	int l=1,r=n;
	while (l+1<=n&&pa(l))l++;
	while (r-1>=1&&pa(r))r--;
	if (l<r) return 0;
	if (l==r&&!pa1(l))return 0;
	puts("YES");
	for (int i=1;i<=l;i++)printf("%d",b[i][1]);
	for (int i=l+1;i<=n;i++)printf("%d",1-b[i][1]);puts("");
	for (int i=1;i<=m;i++)printf("%d",a[1][i]);puts("");
	return 1;
}
bool check2(){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)b[i][j]=a[i][j];
	for (int i=1;i<=m;i++)
		if (!b[n][i])
			for (int j=1;j<=n;j++)b[j][i]^=1;
	int l=1,r=n;
	while (l+1<=n&&pa(l))l++;
	while (r-1>=1&&pa(r))r--;
	if (l<r) return 0;
	if (l==r&&!pa1(l))return 0;
	puts("YES");
	for (int i=1;i<=l;i++)printf("%d",b[i][1]);
	for (int i=l+1;i<=n;i++)printf("%d",1-b[i][1]);puts("");
	for (int i=1;i<=m;i++)printf("%d",1-a[n][i]);puts("");
	return 1;
}
int main(){
	read(n);read(m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)read(a[i][j]);
	if (n==1){
		puts("YES");
		puts("1");
		for (int j=1;j<=m;j++)printf("%d",a[1][j]);puts("");
	}else{
		if (check1())return 0;
		if (check2())return 0;
		puts("NO");
	}
	return 0;
}