#include<bits/stdc++.h>//sss
#define ll long long
using namespace std;
const int MAXN=2e5+10;
int n,l[MAXN],r[MAXN];ll f[MAXN];
int main(){
	scanf("%d",&n);n*=2;
	for(int i=0;i<n;i++){
		int tmp;
		scanf("%d",&tmp);
		if(!l[tmp]) l[tmp]=i;
		else r[tmp]=i;
	}
	n/=2;
	for(int i=1;i<=n;i++){
		int t1=abs(l[i]-l[i-1])+abs(r[i]-r[i-1]),t2=abs(l[i]-r[i-1])+abs(r[i]-l[i-1]);
		f[i]=f[i-1]+min(t1,t2);
	}
	cout<<f[n];
}