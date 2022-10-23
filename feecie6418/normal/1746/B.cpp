#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr; 
int n,a[200005];
void Solve(){
	cin>>n;
	int s1=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]),s1+=a[i];
	}
	int ans=0;
	for(int i=n-s1+1;i<=n;i++)if(!a[i])ans++;
	cout<<ans<<'\n';
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}