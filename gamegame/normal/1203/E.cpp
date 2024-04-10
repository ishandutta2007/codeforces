#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n;
int a[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int p=0,q=0;
	for(int i=1; i<=n ;i++){
		if(a[i]-p>=2) p=a[i]-1,q++;
		else if(a[i]-p>=0) p++,q++;
	}
	cout << q << endl;
}