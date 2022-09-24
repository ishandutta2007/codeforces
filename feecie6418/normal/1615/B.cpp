#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int B=150005;
int s[25][200005];
void Solve(){
	int l,r;
	cin>>l>>r;
	int ans=0;
	for(int i=0;i<20;i++){
		ans=max(ans,s[i][r]-s[i][l-1]);
	}
	cout<<r-l+1-ans<<'\n';
}
int main(){
	for(int i=0;i<20;i++){
		for(int j=1;j<=200000;j++)s[i][j]=s[i][j-1]+((j>>i)&1);
	}
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}