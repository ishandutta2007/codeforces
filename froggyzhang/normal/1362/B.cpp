#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 2333
int n,a[N],b[N],T;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",a+i);
		}
		sort(a+1,a+n+1);
		for(int i=1;i<(1<<10);++i){
			for(int j=1;j<=n;++j){
				b[j]=a[j]^i;
			}
			sort(b+1,b+n+1);
			bool ok=true;
			for(int j=1;j<=n;++j){
				if(b[j]^a[j]){
					ok=false;break;
				}
			}
			if(ok){
				printf("%d\n",i);
				goto END;
			}
		}
		printf("-1\n");
		END:
			continue;
	}
	return 0;
}