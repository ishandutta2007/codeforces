#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,K,lst,a[100005],sum;
int main(){
	cin>>n>>m>>K>>lst;
	for(int i=2,x;i<=n;i++)cin>>x,a[i-1]=x-lst,lst=x;
	sort(a+1,a+n);
	for(int i=1;i<=n-K;i++)sum+=a[i];
	cout<<sum+K;
}