#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define N 5000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define Pi acos(-1.)
#define eps 1e-8
using namespace std;
int n,k,x[N],y[N];double a[N];ll ans;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&x[i],&y[i]);
	rep(i,1,n){
		rep(j,1,i-1)a[j]=atan2(x[j]-x[i],y[j]-y[i]);
		rep(j,i+1,n)a[j-1]=atan2(x[j]-x[i],y[j]-y[i]);
		sort(a+1,a+n);k=1;rep(j,1,n-1)a[j+n-1]=a[j]+Pi*2;
		rep(j,1,n-1){
			while(a[k]-a[j]<Pi)k++;
			ans+=1ll*(k-j-1)*(k-j-2)*(n-k+j-1)*(n-k+j-2)/4;
		}
	}
	printf("%I64d\n",ans/2);
}