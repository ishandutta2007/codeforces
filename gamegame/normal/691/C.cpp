#include<bits/stdc++.h>
using namespace std;
deque<char>d,e;
int b;
int main(){
	string s;cin >> s;
	for(auto cur:s) d.push_back(cur);
	int p=-1;
	int pos=0;
	for(auto cur:d){
		if(cur=='.') p=pos;
		pos++;
	}
	if(p==-1) d.push_back('.');
	while(!d.empty() && d.front()=='0') d.pop_front();
	while(!d.empty() && d.back()=='0') d.pop_back();
	if(d[0]=='.'){
		while(d.size()>1 && d[1]=='0'){
			b--;swap(d[0],d[1]);
			d.pop_front();
		}
		if(d.size()==1) return cout << "0\n",0;
		swap(d[0],d[1]);
		b--;
	}
	p=-1;
	pos=0;
	for(auto cur:d){
		if(cur=='.') p=pos;
		else e.push_back(cur);
		pos++;
	}
	while(e.back()=='0') e.pop_back();
	cout << e[0];
	if(e.size()>1) cout << ".";
	for(int i=1; i<e.size() ;i++) cout << e[i];
	b+=p-1;
	if(b!=0) cout << "E" << b << endl; 
}