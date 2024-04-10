#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000000;
int a[N+10];
int main(){
	int n,L,s=0,c=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&L);
		if(i-L<1)a[1]++;
		else a[i-L]++;
	}
	for(int i=1;i<=n;++i){
		s+=a[i]-1;
		if(s>0)c++;
	}
	printf("%d",n-c);
}