#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 3000
#define ll long long
using namespace std;
int n,m,s,ans,a[N],b[N],A[N],B[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%d",&a[i]);
		a[i]+=a[i-1];A[i]=a[i];
		rep(j,1,i-1)A[i-j]=min(A[i-j],a[i]-a[j]);
	}
	rep(i,1,m){
		scanf("%d",&b[i]);
		b[i]+=b[i-1];B[i]=b[i];
		rep(j,1,i-1)B[i-j]=min(B[i-j],b[i]-b[j]);
	}
	scanf("%d",&s);
	rep(i,1,n)rep(j,1,m)if(1ll*A[i]*B[j]<=s)ans=max(ans,i*j);
	printf("%d",ans);
}