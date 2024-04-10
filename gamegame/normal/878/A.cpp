#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int num1,num2;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	num1=1023;
	for(int i=1; i<=n ;i++){
		char c;
		cin >> c;
		int v;
		cin >> v;
		if(c=='&'){
			num1&=v;
			num2&=v;
		}
		else if(c=='|'){
			num1|=v;
			num2|=v;
		}
		else{
			num1^=v;
			num2^=v;
		}
	}
	int ans1=1023,ans2=0,ans3=0;
	for(int i=9; i>=0 ;i--){
		if((num1&(1<<i))==0 && (num2&(1<<i))==0) ans1^=(1<<i);
		else if((num1&(1<<i))==0 && (num2&(1<<i))!=0) ans3^=(1<<i);
		else if((num1&(1<<i))!=0 && (num2&(1<<i))!=0) ans2^=(1<<i);
	}
	cout << 3 << endl;
	cout << "& " << ans1 << endl << "| " << ans2 << endl << "^ " << ans3 << endl;
}