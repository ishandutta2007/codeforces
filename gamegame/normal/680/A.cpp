#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int b[101];
int main(){
	ios::sync_with_stdio(false);
	int a[6];
	int ans=0,maxi=0;
	for(int i=1; i<=5 ;i++){
		cin >> a[i];
		b[a[i]]++;
		if(b[a[i]]>=2){
			maxi=max(maxi,min(3,b[a[i]])*a[i]);
		}
		ans+=a[i];
	}
	cout << ans-maxi << endl;
}