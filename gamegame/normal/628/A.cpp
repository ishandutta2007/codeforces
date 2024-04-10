#include<iostream>
using namespace std;
int main(){
	int n,b,p,q,r;
	cin >> n >> b >> p;
	int x=0,y=0;
	r=n;
	while(n!=1){
		for(int i=1; i<=10 ;i++){
			if((1<<i)>n){
				q=i-1;
				break;
			}
		}
		x+=(1<<q)/2;
		n=(1<<q)/2+n-(1<<q);
	}
	cout << x*(2*b+1) << ' ' << r*p << endl;
}