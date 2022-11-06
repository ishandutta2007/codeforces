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
#define N 1000000
#define ll long long
#define inf 1000000000
#define mo 1000000007
#define eps 1e-6
using namespace std;
int n,m,x,y,ps,tot,a[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n-1){
		y=x;scanf("%d",&x);
		if((i>1)&&(ps==0))a[++tot]=abs(x-y);
		if(x&1)ps++;else ps--;
	}
	sort(a+1,a+tot+1);
	rep(i,1,tot+1){
		if((i>tot)||(a[i]>m)){
			printf("%d\n",i-1);break;
		}m-=a[i];
	}
}