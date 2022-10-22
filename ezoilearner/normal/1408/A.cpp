#include<bits/stdc++.h>
using namespace std;
int n;
#define Maxn 105
int a[Maxn],b[Maxn],c[Maxn],p[Maxn];

int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i)cin>>b[i];
		for(int i=1;i<=n;++i)cin>>c[i];
		p[1]=a[1];
		for(int i=2;i<n;++i){
			if(a[i]!=p[i-1])p[i]=a[i];
			else if(b[i]!=p[i-1])p[i]=b[i];
			else p[i]=c[i];
		}
		if(a[n]!=p[1]&&a[n]!=p[n-1])p[n]=a[n];
		else if(b[n]!=p[1]&&b[n]!=p[n-1])p[n]=b[n];
		else p[n]=c[n];
		for(int i=1;i<=n;++i)cout<<p[i]<<" ";
		puts("");
	}
	return 0;
}