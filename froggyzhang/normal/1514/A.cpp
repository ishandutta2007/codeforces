#include<bits/stdc++.h>
using namespace std;
#define N 233
int n,a[N],ok[10001];
int main(){
	int T;
	scanf("%d",&T);
	for(int i=1;i*i<=10000;++i)ok[i*i]=1;
	while(T--){
		scanf("%d",&n);
		bool z=false;
		for(int i=1;i<=n;++i){
			scanf("%d",a+i);
			if(!ok[a[i]])z=true;
		}
		printf(z?"YES\n":"NO\n");
	}
	return 0;
}