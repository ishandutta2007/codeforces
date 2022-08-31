#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int maxi=0,last,n;
    cin >> n;
    for(int i=1; i<=n ;i++){
    	cin >> last;
    	maxi=max(maxi,last);
	}
	cout << (maxi^last) << endl;
}