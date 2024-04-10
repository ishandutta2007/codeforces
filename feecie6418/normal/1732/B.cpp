#include<bits/stdc++.h>
const int mod=998244353;
using namespace std;
int n,ans;
char a[100005];
void Solve(){
	scanf("%d%s",&n,a+1);
	int cnt=0;
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(j<n&&a[j+1]==a[i])j++;
		cnt++;
	}
	if(cnt==1)cout<<0<<'\n';
	else {
		int ans=cnt-1;
		if(a[1]=='0')ans--;
		cout<<ans<<'\n';
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve(); 
}