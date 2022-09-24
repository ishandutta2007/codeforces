#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,a[100005];
void Find(int x){
	if(~a[x])return ;
	cout<<"? "<<x<<endl;
	cin>>a[x];
}
void Solve(){
	memset(a,-1,sizeof(a));
	cin>>n,a[0]=a[n+1]=1e9;
	Find(1),Find(n);
	int l=1,r=n;
	while(r-l>30){//baozheng a[l-1]>a[l],a[r+1]>a[r]
		int mid=(l+r)/2;
		Find(mid);
		Find(mid+1);
		if(a[mid]>a[mid+1])l=mid+1;
		else r=mid;
	}
	for(int i=l;i<=r;i++){
		Find(i),Find(i-1),Find(i+1);
		if(a[i]<a[i-1]&&a[i]<a[i+1]){
			cout<<"! "<<i<<endl;
			break;
		}
	}
}
int main(){
	int t=1;
	//cin>>t;
	while(t--)Solve();
}