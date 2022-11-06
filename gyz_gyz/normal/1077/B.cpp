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
int n,ans,a[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,2,n-1)if(!a[i]&&a[i-1]&&a[i+1])a[i+1]=0,ans++;
	printf("%d\n",ans);
}