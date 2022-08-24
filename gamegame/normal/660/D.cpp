#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
#include<unordered_map>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n+1],b[n+1];
	for(int i=1; i<=n ;i++){
		cin >> a[i] >> b[i];
	}
	unordered_map<long long int,int>m;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			if(i==j){
				continue;
			}
			m[(a[i]-a[j])*(2e9+1)+(b[i]-b[j]+1e9)]++;
		}
	}
	int ans=0;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			if(i==j){
				continue;
			}
			ans+=m[(a[i]-a[j])*(2e9+1)+(b[i]-b[j]+1e9)]-1;
		}
	}
	cout << ans/8 << endl;
}