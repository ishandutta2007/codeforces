#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
    int n,d,h;
    cin >> n >> d >> h;
    if(2*h<d){
    	cout << -1 << endl;
	}
    else if(d!=h){
    	for(int i=2; i<=h+1 ;i++){
    		cout << i-1 << ' ' << i << endl;
		}
		cout << 1 << ' ' << h+2 << endl;
		for(int i=h+3; i<=d+1; i++){
			cout << i-1 << ' ' << i << endl;
		}
		for(int i=d+2; i<=n ;i++){
			cout << 1 << ' ' << i << endl;
		}
	}
	else{
		if(d==1 && n==2){
			cout << 1 << ' ' << 2 << endl;
		}
		else if(d!=1){
			for(int i=2; i<=h ;i++){
				cout << i-1 << ' ' << i << endl;
			}
			for(int i=h+1; i<=n ;i++){
				cout << h << ' ' << i << endl;
			}
		}
		else cout << -1 << endl;
	}
}