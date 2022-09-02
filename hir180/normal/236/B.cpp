#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
/*(^(^(^(^(^o^)^)^)^)^) ('') */
long long i,j,k,sum=0,a,b,c,d,e,f;
long long  g[101][101][101]={},sum1=0;
int main(){
	scanf("%lld %lld %lld",&a,&b,&c);
	for(i=1;i<=a;i++){
		for(j=1;j<=b;j++){
			for(k=1;k<=c;k++){
			d=min(i,min(j,k));
			f=max(i,max(j,k));
			e=max(min(max(i,j),k),min(max(k,j),i));
			if(g[d][e][f]!=0){
				sum+=g[d][e][f];
				continue;
			}
			int x=i*j*k;
			for(int h=1;h*h<=x;h++){
				if(x%h==0){
					if(h*h!=x){
					sum+=2;
					sum1+=2;
				}else{
					sum++;
					sum1++;
					}}}
			sum %= 1073741824;
			d=min(i,min(j,k));
			f=max(i,max(j,k));
			e=max(min(max(i,j),k),min(max(k,j),i));
			g[d][e][f]=sum1;
			sum1=0;
			}
		}
	}
	printf("%lld\n",sum);
	return 0;
}