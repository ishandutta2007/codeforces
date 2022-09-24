#include<bits/stdc++.h>
using namespace std;
int n,k,a[300005],fir[300005],las[300005],ans=0;
int main() {
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		cin>>a[i];
		las[a[i]]=i;
		if(!fir[a[i]])fir[a[i]]=i; 
	}
	for(int i=1;i<=n;i++){
		for(int j=max(i-1,1);j<=min(i+1,n);j++)if(!(fir[i]&&las[j]&&las[j]>=fir[i]))ans++;
	}
	cout<<ans;
	return 0;
}