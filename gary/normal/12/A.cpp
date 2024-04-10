#include<bits/stdc++.h>
using namespace std;
int main(){
	char chr[10];
	string temp;
	int chrnum=0;
	for(int i=1;i<=3;i++){
		cin>>temp;
		chr[++chrnum]=temp[0];
		chr[++chrnum]=temp[1];
		chr[++chrnum]=temp[2];
	}
//	cout<<chr[1]<<chr[9];
//	cout<<endl;
//	cout<<chr[2]<<chr[8];
//	cout<<endl;
//	cout<<chr[3]<<chr[7];
//	cout<<endl;
//	cout<<chr[4]<<chr[5];
//	cout<<endl;
	if(chr[1]==chr[9]&&chr[2]==chr[8]&&chr[3]==chr[7]&&chr[4]==chr[6]) cout<<"YES";
	else cout<<"NO";
	return 0;
}