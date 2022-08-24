#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200001],b[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	a[0]=1e9;
	for(int i=1; i<=n+1 ;i++){
		int mi=0;
		for(int j=1; j<=n ;j++) if(a[j]!=0 && a[j]<a[mi]) mi=j;
		if(mi==0){
			cout << i-1 << endl;
			return 0;
		}
		for(int j=1; j<=n ;j++){
			if(j!=mi && a[j]%a[mi]==0) a[j]=0;
		}
		a[mi]=0;
	}
}