#include<iostream>
using namespace std;
int main(){
	long long int x,y,a,b;
	cin >> x >> y >> a >> b;
	x+=8*a;
	if(x>=y){
		cout << 0 << endl;
		return 0;
	}
	x-=12*b;
	for(int i=1; i<=100000 ;i++){
		x+=12*a;
		if(x>=y){
			cout << i << endl;
			return 0;
		}
		x-=12*b;
	}
	cout << -1 << endl;
}