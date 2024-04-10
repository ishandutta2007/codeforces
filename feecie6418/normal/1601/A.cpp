#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[200005]; 
void Solve(){
	cin>>n;
	int cnt[40]={0};
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=0;j<30;j++)if(a[i]&(1<<j))cnt[j]++;
	}
	for(int i=1;i<=n;i++){
		bool f=1;
		for(int j=0;j<30;j++)if(cnt[j]%i)f=0;
		if(f)cout<<i<<' ';
	}
	puts("");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}