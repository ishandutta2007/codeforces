#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 300000
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
int n,tot,a[N],w[N],q1[N],q2[N];ll p1[N],p2[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		p1[i]=p1[i-1]+a[i];
		q1[i]=max(a[i],q1[i-1]);
	}
	dep(i,n,1){
		p2[i]=p2[i+1]+a[i];
		q2[i]=max(a[i],q2[i+1]);
	}
	rep(i,1,n)if(p1[i-1]+p2[i+1]==max(q1[i-1],q2[i+1])*2)w[++tot]=i;
	printf("%d\n",tot);
	rep(i,1,tot)printf("%d ",w[i]);
}