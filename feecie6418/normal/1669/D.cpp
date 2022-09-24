#include<bits/stdc++.h>
using namespace std;
int n;
char a[200005];
void Solve(){
	cin>>n;
	scanf("%s",a+1);
	bool ok=1;
	for(int i=1;i<=n;i++){
		if(a[i]=='W')continue;
		int j=i;
		while(j<n&&a[j+1]!='W')j++;
		bool h1=0,h2=0;
		for(int k=i;k<=j;k++){
			if(a[k]=='R')h1=1;
			if(a[k]=='B')h2=1;
		}
		if(!(h1&&h2))ok=0;
		i=j;
	}
	if(ok)puts("YES");
	else puts("NO");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}