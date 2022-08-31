#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,k;
int a[200001],b[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	if(n%10<5) cout << n-n%10 << endl;
	else cout << n+10-n%10 << endl;
}