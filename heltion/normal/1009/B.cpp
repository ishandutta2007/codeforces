#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	string t1, t2;
	for(int i = 0; i < s.size(); i += 1)
		if(s[i] != '1') t1.push_back(s[i]);
		else t2.push_back('1');
	if(t1.size() == 0){
		cout << s;
		return 0;
	}
	if(t1[0] == '2'){
		cout << t2 + t1;
		return 0;
	}
	string r1, r2;
	for(int i = 0; i < t1.size(); i += 1)
		if(t1[i] == '0') r1.push_back('0');
		else break;
	for(int i = r1.size(); i < t1.size(); i += 1) r2.push_back(t1[i]);
	cout << r1 + t2 + r2;
	return 0;	
}