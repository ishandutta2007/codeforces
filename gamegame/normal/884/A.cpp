#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
int n;
int a[200001];
int t;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> t;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		t-=86400-a[i];
		if(t<=0){
			cout << i << endl;
			return 0;
		}
	}
	
}