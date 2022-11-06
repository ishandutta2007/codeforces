#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define N 131072
#define ll long long
#define mo 1000000007
#define inf 1000000000
using namespace std;
int n,l[N],r[N],a[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&l[i]);
	rep(i,1,n)scanf("%d",&r[i]);
	rep(i,1,n)a[i]=n-l[i]-r[i];
	rep(i,1,n){
		rep(j,1,i-1)if(a[j]>a[i])l[i]--;
		rep(j,i+1,n)if(a[j]>a[i])r[i]--;
		if(l[i]||r[i]){printf("NO");return 0;}
	}
	printf("YES\n");
	rep(i,1,n)printf("%d ",a[i]);
}