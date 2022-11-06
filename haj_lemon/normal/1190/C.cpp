#include<bits/stdc++.h>
#define N 100010
using namespace std;
template <typename T> void read(T &x){
	x=0;char ch=getchar();int fh=1;
	while (ch<'0'||ch>'9'){if (ch=='-')fh=-1;ch=getchar();}
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
int n,k,a[N],s[N],maq[2][N],miq[2][N],mah[2][N],mih[2][N];
bool p=1;
int check0q(int x){if (s[x]==0) return 0;if (maq[1][x]-miq[1][x]<k)return 1;return 2;}
int check1q(int x){if (s[x]==x) return 0;if (maq[0][x]-miq[0][x]<k)return 1;return 2;}
int check0h(int x){if (s[n]-s[x-1]==0)return 0;if (mah[1][x]-mih[1][x]<k)return 1;return 2;}
int check1h(int x){if (s[n]-s[x-1]==n-(x-1))return 0;if (mah[0][x]-mih[0][x]<k)return 1;return 2;}
int main(){
	read(n);read(k);
	for (int i=1;i<=n;i++){char ch=getchar();while (ch!='0'&&ch!='1')ch=getchar();a[i]=ch-'0';}
	for (int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for (int i=1;i<=n;i++){
		for (int j=0;j<=1;j++)maq[j][i]=maq[j][i-1],miq[j][i]=miq[j][i-1];
		maq[a[i]][i]=i;if (miq[a[i]][i]==0)miq[a[i]][i]=i;
	}
	for (int i=n;i>=1;i--){
		for (int j=0;j<=1;j++)mah[j][i]=mah[j][i+1],mih[j][i]=mih[j][i+1];
		mih[a[i]][i]=i;if (mah[a[i]][i]==0)mah[a[i]][i]=i;		
	}
	for (int i=1;i<=n-k+1;i++){
		if (s[i-1]+s[n]-s[i+k-1]+k==n){puts("tokitsukaze");return 0;}
		if (s[i-1]+s[n]-s[i+k-1]==0){puts("tokitsukaze");return 0;}
		if (check0q(i-1)+check0h(i+k)>1||check1q(i-1)+check1h(i+k)>1)p=0;
	}
	if (p)puts("quailty");else puts("once again");
	return 0;
}