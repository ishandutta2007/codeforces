#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,is[100005];
ll m;
void Solve(){
	cin>>n>>m;
	if(n<=62&&m>(1ll<<n-1)){
		puts("-1");
		return ;
	}
	m--;
	for(int i=0;i<n-1&&i<61;i++){
		if(m&(1ll<<i)){
			is[n-i-1]=1;
		}
	}
	for(int i=1,cur=1;i<=n;i++){
		if(!is[i]){
			cout<<cur<<' ';
			cur++;
			continue;
		}
		int j=i;
		while(is[j])j++;
		for(int k=i;k<=j;k++)cout<<cur+(j-k)<<' ';
		cur+=j-i+1;
		i=j;
	}
	puts("");
	for(int i=1;i<=n;i++)is[i]=0;
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}