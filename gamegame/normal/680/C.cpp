#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int prime[20]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,49,0};
	int cnt=0;
	string ans;
	for(int i=0; i<19 ;i++){
		cout << prime[i] << endl;
		fflush(stdout);
		cin >> ans;
		cnt+=(ans=="yes");
	}
	if(cnt<=1) cout << "prime\n";
	else cout << "composite\n";
}