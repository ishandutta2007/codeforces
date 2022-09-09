#include<bits/stdc++.h>
using namespace std;
int read(){
	int x = 0;
	char c;
	bool pos = true;
	do{
		c = getchar();
		if(c == '-') pos = false;
	}while(c < '0' or c > '9');
	do{
		x = x * 10 + c - '0';
		c = getchar();
	}while(c >= '0'  and c <= '9');
	return pos ? x : - x;
}


int main(){
	set<string> se;
	for(int n = read(); n; n -= 1){
		string s;
		cin>>s;
		int a[26];
		for(int i = 0; i < 26; i += 1) a[i] = 0;
		for(int i = 0; i < s.size(); i += 1) a[s[i] - 'a'] = 1;
		string ss;
		for(int i = 0; i < 26; i += 1) if(a[i]) ss.push_back(i + 'a');
		if(se.find(ss) == se.end()) se.insert(ss);
	}
	printf("%d", se.size());
}