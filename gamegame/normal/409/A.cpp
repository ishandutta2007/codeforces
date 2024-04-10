#include<iostream>
using namespace std;
int f(char u,char v){
	if(u=='8') return 1;
	if(u=='(') return 0;
	return 2;
}
int main(){
	string s,t;
	cin >> s >> t;
	int s1=0,s2=0;
	for(int i=0; i<s.size() ;i+=2){
		int num1=f(s[i],s[i+1]),num2=f(t[i],t[i+1]);
		if(num1==num2) continue;
		else if(num2==(num1+1)%3) s1++;
		else s2++;
	}
	if(s1<s2) cout << "TEAM 2 WINS";
	else if(s1>s2) cout << "TEAM 1 WINS";
	else cout << "TIE";
}