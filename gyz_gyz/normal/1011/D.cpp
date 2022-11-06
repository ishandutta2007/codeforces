#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define gc getchar()
#define N 200010
#define ll long long
#define inf 1000000000
#define mo 998244353
#define eps 1e-6
using namespace std;
int n,m,l,r,mid,res,a[50];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,0,m-1){
		printf("1\n");fflush(stdout);
		scanf("%d",&a[i]);
		if(a[i]==0)return 0;
	}
	l=2;r=n;mid=(l+r)/2;
	rep(i,0,60){
		printf("%d\n",mid);fflush(stdout);
		scanf("%d",&res);if(a[i%m]==-1)res=-res;
		if(res==0)return 0;
		if(res==1)l=mid+1;
		if(res==-1)r=mid-1;
		mid=(l+r)/2;
	}
}