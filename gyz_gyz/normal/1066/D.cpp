#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 200010
#define ll long long
#define pb push_back
#define add(x,y) x=(x+(y))%mo;
#define sqr(x) ((x)*(x))
#define mo 998244353
#define inf 1000000000
#define eps 1e-8
using namespace std;
int n,m,k,x,y,a[N];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n)scanf("%d",&a[i]);x=m;y=k;
	dep(i,n,1){
		if(y<a[i]){
			if(x==1){
				printf("%d",n-i);return 0;
			}
			x--;y=k-a[i];
		}else y-=a[i];
	}
	printf("%d",n);
}