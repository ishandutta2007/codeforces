#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pr;
int n,m;
char a[55],b[55];
void Solve(){
	cin>>n>>m>>a+1>>b+1;
	for(int i=2;i<=m;i++)if(b[i]!=a[n-m+i])return puts("No"),void();
	for(int i=1;i<=n-m+1;i++)if(b[1]==a[i])return puts("Yes"),void();
	puts("No");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}