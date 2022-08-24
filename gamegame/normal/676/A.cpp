#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int n,pos1,pos2;
	cin >> n;
	int a[n+1];
	int mini=2e9,maxi=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		if(a[i]<mini){
			mini=a[i];
			pos1=i;
		}
		if(a[i]>maxi){
			maxi=a[i];
			pos2=i;
		}
	}
	cout << max(max(n-pos1,pos1-1),max(n-pos2,pos2-1));
}