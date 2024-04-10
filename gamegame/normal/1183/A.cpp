#include<bits/stdc++.h>
using namespace std;
int sum(int x){
	int s=0;
	while(x>0){
		s+=x%10;
		x/=10;
	}
	return s%4;
}
int main(){
    ios::sync_with_stdio(false);
    int n;cin >> n;
    while(sum(n)) n++;
    cout << n << endl;
}