#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
int n,a[2005],f[30000005],s=0;
ll ans=1e18;
int Get(int x){
	if(f[x]!=-1)return f[x];
	
	s++;
	
//	for(int i=1;i<=n;i++)if(a[i]>x)return f[x]=n+1;
//	int ans=0;
//	for(int i=1,j;i<=n;i=j+1){
//		int s=a[i];
//		j=i;
//		while(j<n&&s+a[j+1]+1<=x)s+=a[j+1]+1,j++;
//		ans++;
//	}
//	return f[x]=ans;
	
	assert(s<=n+30);
	int ans;
	cout<<"? "<<x<<endl;
	cin>>ans;
	if(ans==0)ans=n+1;
	return f[x]=ans;
}
void Solve(int l1,int r1,int l2,int r2){
	if(l2>r2||l1>r1||l2==n+1)return ;
	if(1ll*l1*l2>=ans||l2==n+1)return ;
	if(l2==r2){
		if(l2!=n+1)ans=min(ans,1ll*l1*l2);
		return ;
	}
	//cout<<l1<<' '<<r1<<' '<<l2<<' '<<r2<<'\n';
	int mid=(l1+r1)/2,u=Get(mid);
	if(u!=n+1)ans=min(ans,1ll*mid*u);
	Solve(l1,mid-1,u,r2);
	Solve(mid+1,r1,l2,u);
}
int main(){
	//srand(time(0));
	memset(f,-1,sizeof(f));
	cin>>n;
	
	//for(int i=1;i<=n;i++)a[i]=rand()%2000+1;
	//for(int i=1;i<=n;i++)cin>>a[i];
	int l=1,r=2001*n;
	while(l<=r){
		int mid=(l+r)/2;
		if(Get(mid)==1)r=mid-1,ans=mid;
		else l=mid+1;
	}
	
	Solve(1,ans-1,2,n+1);
	
	cout<<"! "<<ans<<endl;
	//cerr<<s;
}