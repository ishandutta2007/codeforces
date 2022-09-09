#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 120;
char s[maxn];
int main(){
	int n;
	scanf("%d", &n);
	while(n --){
		set<int> si;
		scanf("%s", s);
		for(int i = 0; s[i]; i += 1) si.insert(s[i]);
		if(*si.rbegin() - *si.begin() + 1 == strlen(s)
			and si.size() == strlen(s)) puts("Yes");
		else puts("No");
	}
}