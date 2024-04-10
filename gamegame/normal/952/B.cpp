#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	int cnt=0;
	for(int i=0; i<10 ;i++){
		int num=i%10;
		cout << num << endl;
		string s;
		getline(cin,s);
		if(s=="no") cnt++;
		if(s=="terrible" || s=="worse" || s=="no way" || s=="go die in a hole" || s=="don't even" || s=="are you serious?"){
			cout << "grumpy" << endl;
			return 0;
		}
		if(s=="great!" || s=="not bad" || s=="cool" || s=="don't touch me!" || s=="don't think so" || cnt>3){
			cout << "normal" << endl;
			return 0;
		}
	}
	cout << "normal" << endl;
}