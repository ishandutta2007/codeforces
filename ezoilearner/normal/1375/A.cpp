#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
#define Maxn 10010
int a[Maxn],b[Maxn];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int at1=0,at2=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)
		   if(i&1)b[i]=abs(a[i]);
		   else b[i]=-abs(a[i]);
		for(int i=1;i<=n;++i)printf("%d ",b[i]);
		puts("");
	}
	return 0;
}