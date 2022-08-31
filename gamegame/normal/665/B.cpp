#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,m,k;
	cin >> n >> m >> k;
	int a[k+1],b[k+1];
	for(int i=1; i<=k ;i++){
		cin >> a[i];
	}
	int cost=0;int tem;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cin >> tem;
			for(int l=1; l<=k ;l++){
				if(a[l]==tem){
					cost+=l;
					for(int p=l; p>=2 ;p--){
						swap(a[p],a[p-1]);
					}
					break;
				}
			}
		}
	}
	cout << cost << endl;
}