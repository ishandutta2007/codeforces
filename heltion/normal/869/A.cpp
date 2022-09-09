#include<iostream>
using namespace std;
int main(){
	int n,c;
	cin>>n;
	for(int i=0;i<2*n;++i){
		cin>>c;
		if(!c)break;	
	}
	if((!c)&&(n%2))cout<<"Koyomi";
	else cout<<"Karen"; 
}