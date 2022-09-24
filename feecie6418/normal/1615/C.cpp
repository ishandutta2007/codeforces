#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int B=150005;
int n;
char a[100005],b[100005];
void Solve(){
	cin>>n>>a+1>>b+1;
	int s=0,ans=1e9,s1=0,s2=0;
	for(int i=1;i<=n;i++)s+=(a[i]!=b[i]),s1+=(a[i]!=b[i]&&a[i]=='1'),s2+=(a[i]==b[i]&&a[i]=='1');
	if(s%2==0&&s1+s1==s)ans=min(ans,s);
	if((n-s)%2==1&&s2+s2-1==n-s)ans=min(ans,n-s);
	if(ans==1e9)puts("-1");
	else cout<<ans<<'\n';
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}