#include<iostream>
using namespace std;
int occ[5001];
int a[5001];
int maxi,maxnum;
int ans[5001];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n ;i++) cin >> a[i];
	for(int i=1; i<=n ;i++){
		maxi=0,maxnum=1;
		for(int j=i; j<=n ;j++){
			occ[a[j]]++;
			if(occ[a[j]]>maxi || occ[a[j]]==maxi && maxnum>a[j]){
				maxi=occ[a[j]];
				maxnum=a[j];
			}
			ans[maxnum]++;
		}
		for(int i=1; i<=n ;i++){
			occ[i]=0;
		}
	}
	for(int i=1; i<=n ;i++) cout << ans[i] << ' ';
}