#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e18;
typedef pair<ll,ll> pr;
int n,a[355][355],b[355];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>b[i],a[i][i]=b[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j==i)continue;
			a[i][j]=(a[i][i]+(i-j+n)*i)%n;
		}
		for(int j=0;j<n;j++)cout<<a[i][j]<<' ';
		puts("");
	}/*
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=i+1;k<n;k++){
				for(int l=j+1;l<n;l++){
					assert((a[i][j]+a[k][l])%n!=(a[i][l]+a[k][j])%n);
				}
			}
		}
	}*/
}