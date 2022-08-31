#include<bits/stdc++.h>
using namespace std;
string s;
int f[226];
deque<char>v;
int main(){
	ios::sync_with_stdio(false);
	cin >> s;
	for(auto cur:s){
		f[cur]++;
	}
	for(int i='a'; i<='z' ;i++){
		if(f[i]%2) v.push_back(i);
	}
	while(v.size()>1){
		f[v.front()]++;
		f[v.back()]--;
		v.pop_front();v.pop_back();
	}
	for(char i='a'; i<='z' ;i++){
		for(int j=0; j<f[i]/2 ;j++){
			cout << i;
		}
	}
	if(s.size()%2) cout << v.back();
	
	for(char i='z'; i>='a' ;i--){
		for(int j=0; j<f[i]/2 ;j++){
			cout << i;
		}
	}
}