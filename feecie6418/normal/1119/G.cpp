#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
int n,m,a[1000005],b[1000005],c[1000005];
int main(){
	cin>>n>>m;
	int s=0;
	for(int i=1;i<=m;i++)cin>>a[i],s+=a[i],b[i]=s%n;
	s=(s+n-1)/n,cout<<s<<'\n';
	b[m]=n,sort(b+1,b+m+1);
	for(int i=1;i<=m;i++)cout<<(c[i]=b[i]-b[i-1])<<' ';
	puts("");
	for(int i=1,j=1;i<=m;i++){
		while(a[i]>0){
			a[i]-=c[j],cout<<i<<' ';
			if(j==m)puts("");
			j=j%m+1;
		}
		if(i==m){
			while(j<=m&&j!=1)cout<<i<<' ',j++;
		}
	}
}