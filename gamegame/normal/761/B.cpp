#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,k;
int a[2001],b[2001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	for(int i=1; i<=n ;i++){
		cin >> b[i];
	}
	int dis;
	for(int i=1; i<=n ;i++){
		dis=(b[i]-a[1]+m)%m;
		bool ok=true;
		for(int j=1,k=i; j<=n ;j++,k=k%n+1){
			if((a[j]+dis)%m!=b[k]) ok=false;
		}
		if(ok){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}