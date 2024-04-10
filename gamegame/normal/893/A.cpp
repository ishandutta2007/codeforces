#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
int n,m,k;
bool hv[4];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	hv[1]=true;
	hv[2]=true;
	for(int i=1; i<=n ;i++){
		cin >> k;
		if(!hv[k]){
			cout << "NO\n";
			return 0;
		}
		for(int j=1; j<=3 ;j++){
			if(hv[j] && j!=k){
				hv[j]=false;
			}
			else hv[j]=true;
		}
	}
	cout << "YES\n";
}