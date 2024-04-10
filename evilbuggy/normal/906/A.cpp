#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	set<char> st;
	int answer = 0;
	for(char c = 'a'; c <= 'z'; c++){
		st.insert(c);
	}
	for(int i = 0; i < n; i++){
		char op;
		string str;
		cin >> op >> str;
		if(op == '.'){
			for(auto ch : str){
				st.erase(ch);
			}
		}else if(op == '!'){
			if(st.size() == 1){
				answer++;
				continue;
			}
			set<char> nst;
			for(auto ch : str){
				if(st.count(ch))nst.insert(ch);
			}
			st = nst;
		}else{
			if(st.size() == 1){
				char ch = *st.begin();
				if(ch != str[0]){
					answer++;
				}
			}else{
				st.erase(str[0]);
			}
		}
	}
	cout << answer << '\n';

	return 0;
}