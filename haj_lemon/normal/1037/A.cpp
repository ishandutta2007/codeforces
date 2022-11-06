#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,ansn=0;
	cin>>x;
	while (x){
		x/=2;ansn++;
	}
	cout<<ansn<<endl;
	return 0;
}