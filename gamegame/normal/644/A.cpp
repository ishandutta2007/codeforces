#include<iostream>
using namespace std;
int main(){
	int n,a,b;
	cin >> n >> a >> b;
	if(n>a*b){
		cout << -1 << endl;
	}
	else if(b%2==0){
		for(int i=1; i<=a ;i++){
			if(i%2==0){
				for(int j=b; j>=1 ;j--){
					if((i-1)*b+j>n){
						cout << 0;
					}
					else{
						cout << (i-1)*b+j;
					}
					if(j==1){
						cout << endl;
					}
					else{
						cout << ' ';
					}
				}
			}
			else{
				for(int j=1; j<=b ;j++){
					if((i-1)*b+j>n){
						cout << 0;
					}
					else{
						cout << (i-1)*b+j;
					}
					if(j==b){
						cout << endl;
					}
					else{
						cout << ' ';
					}
				}
			}
		}
	}
	else{
		for(int i=1; i<=a ;i++){
			for(int j=1; j<=b ;j++){
				if((i-1)*b+j>n){
					cout << 0;
				}
				else{
					cout << (i-1)*b+j;
				}
				if(j==b){
					cout << endl;
				}
				else{
					cout << ' ';
				}
			}
		}
	}
}