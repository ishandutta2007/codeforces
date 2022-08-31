#include<iostream>
using namespace std;
int main(){
	int n,ext=0;
	cin >> n;
	for(int i=n+1;  ;i++){
		ext+=1+(i%4==0 && (i%100!=0 || i%400==0) );
		if(ext%7==0 && (i%4==0 && (i%100!=0 || i%400==0) )==(n%4==0 && (n%100!=0 || n%400==0) )){
			cout << i << endl;
			return 0;
		}
	}
}