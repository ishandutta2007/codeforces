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
int n,m,x,u,a[200],b[200];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){scanf("%d",&x);a[x]++;}
	rep(i,1,101){
		rep(j,1,100)b[j]=a[j];
		rep(j,1,n){x=0;
			rep(k,1,100)if(b[x]<b[k])x=k;
			if(b[x]<i){u=1;break;}else b[x]-=i;
		}
		if(u){printf("%d\n",i-1);break;}
	}
}