#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
int n,a[2005];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=a[n]-a[1];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i!=1&&j!=n)continue;
			for(int k=0;k<j-i+1;k++){
				int an=a[n],a1=a[1];
				if(i==1)a1=a[1+k];
				if(j==n)an=a[(n-i+k)%(j-i+1)+i];
				ans=max(ans,an-a1);
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve(); 
}