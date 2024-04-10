#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define abs(x) ((x)<0?-(x):(x))
#define N 100000
#define M 301
#define ll long long
#define inf 1000000000
using namespace std;
int n,tot,p,nm,a[20];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);tot+=a[i];
	}
	rep(i,1,(1<<n)-2){p=nm=0;
		rep(j,1,n)if((i>>(j-1))&1)p+=a[j],nm++;
		if(p*2!=tot){
			printf("%d\n",nm);
			rep(j,1,n)if((i>>(j-1))&1)printf("%d ",j);
			return 0;
		}
	}
	printf("-1");
}