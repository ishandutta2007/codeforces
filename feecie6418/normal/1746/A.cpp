#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr; 
int n,k,a[55],s[55],f[55];
void Solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i],s[i]=s[i-1]+a[i];
	}
	if(s[n])puts("YES");
	else puts("NO");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}