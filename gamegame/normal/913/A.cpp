#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
int n,m,k;
int a[200001],b[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	long long num=1;
	for(int i=1; i<=n ;i++){
		num*=2;
		if(num>m){
			cout << m << endl;
			return 0;
		}
	}
	cout << m%num << endl;
}