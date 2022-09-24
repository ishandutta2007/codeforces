#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
vector<int> vec[200005];
void Prime(int x){
	int p=0;
	for(int i=2;i*i<=x;i++){
		if(x%i)continue;
		p=0;
		while(x%i==0)p++,x/=i;
		vec[i].push_back(p);
	}
	if(x>1)vec[x].push_back(1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)Prime(a[i]);
	long long ans=1;
	for(int i=2;i<=200000;i++){
		if(!vec[i].size())continue;
		sort(vec[i].begin(),vec[i].end());
		if(vec[i].size()==n)for(int j=1;j<=vec[i][1];j++)ans*=i;
		else if(vec[i].size()==n-1)for(int j=1;j<=vec[i][0];j++)ans*=i;
	}
	cout<<ans;
	return 0;
}