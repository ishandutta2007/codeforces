#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n,a;
	cin >> n >> a;
	bool b[n+1];
	for(int i=1; i<=n ;i++){
		cin >> b[i];
	}
	int r,l=r=a,ans=0;
	while(l>0 && r<=n){
		if(b[l] && b[r]){
			ans+=2-(l==r);
		}
		l--;r++;
	}
	while(l>0){
		ans+=b[l];
		l--;
	}
	while(r<=n){
		ans+=(int)b[r];
		r++;
	}
	cout << ans << endl;
}