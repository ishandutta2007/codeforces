#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7,N=1e9;
int m,n,b[200005],a[100005],f[100005];
bool Check(int mid){
	//1 
	f[1]=0;
	for(int i=2;i<=n;i++){
		f[i]=f[i-1];
		if(f[i-1]>=a[i]-1)f[i]=max(f[i],a[i]+mid);
		if(f[i-1]>=a[i]-mid-1)f[i]=max(f[i],a[i]);
		if(i>2&&f[i-2]>=a[i]-mid-1)f[i]=max(f[i],a[i-1]+mid);
	}
	if(f[n]>=m-mid-1)return 1;
	
	//2 
	if(a[2]-mid<0){
		f[2]=max(a[2],a[1]+mid);
		for(int i=3;i<=n;i++){
			f[i]=f[i-1];
			if(f[i-1]>=a[i]-1)f[i]=max(f[i],a[i]+mid);
			if(f[i-1]>=a[i]-mid-1)f[i]=max(f[i],a[i]);
			if(i>2&&f[i-2]>=a[i]-mid-1)f[i]=max(f[i],a[i-1]+mid);
		}
		if(f[n]>=min(m-1,a[2]+m-mid-1))return 1;
	}
	
	//1 
	f[1]=mid;
	for(int i=2;i<=n;i++){
		f[i]=f[i-1];
		if(f[i-1]>=a[i]-1)f[i]=max(f[i],a[i]+mid);
		if(f[i-1]>=a[i]-mid-1)f[i]=max(f[i],a[i]);
		if(i>2&&f[i-2]>=a[i]-mid-1)f[i]=max(f[i],a[i-1]+mid);
	}
	if(f[n]>=m-1)return 1;
	
	return 0;
}
int main(){
	cin>>m>>n;
	for(int i=1;i<=n;i++)cin>>b[i];
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)b[i+n]=b[i]+m;
	int mx=0;
	for(int i=1;i<=n;i++)mx=max(mx,b[i+1]-b[i]);
	for(int i=1;i<=n;i++){
		if(b[i+1]-b[i]==mx){
			for(int j=i+1;j<=i+n;j++)a[j-i]=b[j]-b[i+1];
			break;
		}
	}
	int l=0,r=m-1,ans=m-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(Check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans;
}