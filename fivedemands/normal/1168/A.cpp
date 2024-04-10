#include<iostream>
using namespace std;
int n,m;
int a[300001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	int l=0,r=m;
	while(l!=r){
		int mid=(l+r)/2;
		int mi=0;
		bool ok=true;
		for(int i=1; i<=n ;i++){
			if(a[i]>=mi){
				if(a[i]+mid>=m && a[i]+mid-m>=mi) continue;
				else mi=a[i];
			}
			else if(a[i]+mid>=mi) continue;
			else{
				ok=false;break;
			}
		}
		if(ok) r=mid;
		else l=mid+1;
	}
	cout << l << endl;
}