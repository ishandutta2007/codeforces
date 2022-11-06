#include<bits/stdc++.h>
#define INF 1000000000000ll
#define N 100010
#define ll long long
using namespace std;
int n,k,a[N],f[N];
ll di[N],dp[N],sum;
void add(int x){sum+=f[a[x]];f[a[x]]++;}
void dec(int x){f[a[x]]--;sum-=f[a[x]];}
void trans(int l1,int r1,int l2,int r2){
	if (l2>r2)return ;
	int mid=(l2+r2)/2,no=l1;
	for (int i=l2;i<=mid;i++)add(i);
	for (int i=l1;i<=r1&&i<mid;i++){
		dec(i);
		if (dp[mid]>di[i]+sum){dp[mid]=di[i]+sum;no=i;}
	}
	for (int i=no;i<=r1&&i<mid;i++)add(i);
	trans(no,r1,mid+1,r2);
	for (int i=l2;i<=mid;i++)dec(i);
	for (int i=l1;i<no;i++)add(i);
	trans(l1,no,l2,mid-1);
}
int main(){
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=0;i<=n;i++)di[i]=dp[i]=INF;di[0]=0;
	for (int i=1;i<=k;i++){
		add(i-1);trans(i-1,n-1,i,n);dec(i-1);
		for (int j=0;j<=n;j++)di[j]=dp[j],dp[j]=INF;
	}
	cout<<di[n]<<endl;
	return 0;
}