#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, m;
	cin>>n>>m;
	deque<char> s, t;
	char ch;
	for(int i = 0; i < n; i++){
		cin>>ch;
		s.push_back(ch);
	}
	for(int i = 0; i < m; i++){
		cin>>ch;
		t.push_back(ch);
	}
	while(!s.empty() && !t.empty() && s.front() == t.front()){
		s.pop_front();
		t.pop_front();
	}
	while(!s.empty() && !t.empty() && s.back() == t.back()){
		s.pop_back();
		t.pop_back();
	}
	if((t.empty() && s.empty()) || (s.size() == 1 && s[0] == '*')){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}

	return 0;
}