#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	cin>>n>>s;
	bitset<1005>b(s),a;
	for(int i=1;i<=n/2;i++){
		a.set(2*i-1);
	}
	cout<<min((a^b).count(),n-(a^b).count());
	return 0;
}