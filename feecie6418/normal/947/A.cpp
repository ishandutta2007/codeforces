#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353,N=1e6;
int n,bad[N+5];
int main(){
	cin>>n;
	int tn=n,mx=1;
	for(int i=2;i*i<=tn;i++){
		if(tn%i)continue;
		mx=max(mx,i);
		while(tn%i==0)tn/=i;
	}
	mx=max(mx,tn);
	int m=n-mx+1,ans=1e9;
	for(int i=2;i<=n;i++){
		if(bad[i])continue;
		for(int j=i+i;j<=n;j+=i){
			bad[j]=1;
			if(j>=m&&j<=n)ans=min(ans,j-i+1);
		}
	}
	cout<<ans;
}