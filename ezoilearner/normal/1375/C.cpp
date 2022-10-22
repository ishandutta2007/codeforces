#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
#define Maxn 300010
int a[Maxn];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		if(a[n]>a[1]){
			puts("YES");
			continue;
		}
		puts("NO");
	}
    return 0;
}