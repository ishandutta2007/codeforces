#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
template <typename T> void read(T &x){
	x=0;char ch=getchar();int fh=1;
	while (ch<'0'||ch>'9'){if (ch=='-')fh=-1;ch=getchar();}
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
int n,a[N],c1;
int main(){
	read(n);
	for (int i=1;i<=n;i++)read(a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<n;i++){if (a[i]==a[i+1]){if ((i!=1&&a[i-1]+1==a[i])||a[i]==0)c1++;c1++;}}
	if (c1>=2){
		puts("cslnb");
	}else{
		ll su=0;
		for (int i=1;i<=n;i++)su+=a[i]-i+1;
		if (su%2==1) puts("sjfnb");else puts("cslnb");
	}
	return 0;
}