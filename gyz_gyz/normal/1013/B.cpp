#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define N 200000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,x,a[N],v[N]; 
int main(){
	scanf("%d%d",&n,&x);
	rep(i,1,n){
		scanf("%d",&a[i]);
		if(v[a[i]]){printf("0");return 0;}
		v[a[i]]=i;
	}
	rep(i,1,n)if(v[a[i]&x]&&(v[a[i]&x]!=i)){
		printf("1");return 0;
	}
	rep(i,1,n){
		if(v[a[i]&x]&&(v[a[i]&x]!=i)){
			printf("2");return 0;
		}		
		v[a[i]&x]=i;
	}
	printf("-1");
}