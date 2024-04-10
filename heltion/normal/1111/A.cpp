#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define maxn 1200
char s[maxn], t[maxn];
void no(){
	cout << "No";
	exit(0);
}
bool vow(char c){
	if(c == 'a') return true;
	if(c == 'o') return true;
	if(c == 'e') return true;
	if(c == 'i') return true;
	if(c == 'u') return true;
	return false;
}
int main(){
	cin >> s >> t;
	if(strlen(s) != strlen(t)) no();
	for(int i = 0; s[i]; i += 1)
		if(vow(s[i]) ^ vow(t[i]))
			no();
	cout << "Yes";
}