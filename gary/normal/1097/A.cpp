#include<bits/stdc++.h>
using namespace std;
int main(){
	char const_rant,const_suit,temp_rant,temp_suit;
	cin>>const_rant>>const_suit;
	for(int i=1;i<=5;i++){
		cin>>temp_rant>>temp_suit;
		if(temp_rant==const_rant||temp_suit==const_suit){
			cout<<"YES"<<endl;
			return 0;
		}
	} 
	cout<<"NO"<<endl;
	return 0;
}