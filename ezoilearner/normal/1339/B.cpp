#include<iostream> 
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int T,n;
#define Maxn 100010
int a[Maxn],b[Maxn];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int l=(n+1)/2,r=(n+1)/2;
		b[1]=a[l];
		for(int i=2;i<=n;++i){
			if(i%2==0){
				r++;
				b[i]=a[r];
			}else{
				l--;
				b[i]=a[l];
			}
		} 
		for(int i=1;i<=n;++i)printf("%d ",b[i]);
		puts(""); 
	} 
	return 0;
}