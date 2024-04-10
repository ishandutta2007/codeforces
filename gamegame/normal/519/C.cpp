#include<iostream>
using namespace std;
int main(){
	int a,b,x,y;
	cin >> a >> b;
	x=min(a,b);
	y=max(a,b);
	if(x*2<y){
		cout << x << endl;
	}
	else{
		int z=2*x-y;
		int w=y-x;
		cout << w+(z/3)*2+(z%3)/2 << endl;
	}
}