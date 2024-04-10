#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 200000
#define ll long long
using namespace std;
int n,a[N],b[N];ll ans;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&a[i],&b[i]);
	sort(a+1,a+n+1);sort(b+1,b+n+1);
	rep(i,1,n)ans+=max(a[i],b[i])+1;
	printf("%I64d",ans);
}