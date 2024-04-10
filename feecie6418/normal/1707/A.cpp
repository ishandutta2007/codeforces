#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,q,a[100005],s[100005],nd[100005];
void Solve(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]+(a[i]<=q);
	}
	for(int i=n;i>=1;i--){
		if(nd[i+1]>=a[i])nd[i]=nd[i+1];
		else nd[i]=nd[i+1]+1;
	}
	int mx=-1,mxp=0;
	for(int i=0;i<=n;i++){
		if(q>=nd[i+1]&&s[i]+(n-i)>mx){
			mx=s[i]+(n-i);
			mxp=i;
		}
	}
	for(int i=1;i<=mxp;i++)if(a[i]<=q)cout<<1;else cout<<0;
	for(int i=mxp+1;i<=n;i++)cout<<1;
	puts("");
	for(int i=1;i<=n;i++)a[i]=s[i]=nd[i]=0;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}