#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int n,m,k;
int hv[4000001];
int x[2001],y[2001];
int main(){
	ios::sync_with_stdio(false);
	long long a,b;
	cin >> a >> b;
	if(b-a>10){
		cout << 0 << endl;
		return 0;
	}
	int num=1;
	for(long long i=a+1; i<=b ;i++){
		num*=(i%10);
		num%=10;
	}
	cout << num << endl;
}