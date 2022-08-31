#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	bool alla=true;
	for(int i=0; i<s.size() ;i++){
		if(s[i]!='a'){
			alla=false;
			break;
		}
	}
	if(alla){
		s[s.size()-1]='z';
	}
	else{
		for(int i=0; i<s.size() ;i++){
			if(s[i]!='a'){
				while(i!=s.size() && s[i]!='a'){
					s[i]--;
					i++;
				}
				break;
			}
		}
	}
	cout << s << endl;
}