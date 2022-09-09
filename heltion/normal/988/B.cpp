#include<cstdio>
#include<string>
#include<iostream>
#define maxn 1000
std::string s[maxn];
bool issub(std::string a, std::string b){
	for(int i = 0; i + a.size() <= b.size(); i += 1){
		bool flag = true;
		for(int j = 0; j < a.size(); j += 1)
			if(a[j] != b[i + j]) flag = false;
		if(flag) return true;
	}
	return false;
}
int main(){
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i += 1) std::cin >> s[i];
	for(int i = 1; i <= n; i += 1)
		for(int i = 1; i < n; i += 1){
			bool a = issub(s[i], s[i + 1]);
			bool b = issub(s[i + 1], s[i]);
			if(a == false and b == false) return std::cout << "NO", 0;
			if(a == false and b == true) swap(s[i], s[i + 1]);
		}
	std::cout << "YES" << std::endl;
	for(int i = 1; i <= n; i += 1) std::cout << s[i] << std::endl;
}