#include<bits/stdc++.h>
#define maxn 240000
using namespace std;
char s[maxn];
int main(){
	int n, t = 0;
	cin >> n >> s;
	for(int i = 0; i < n; i += 1){
		if(t == 0 && s[i] > s[i + 1]){
			t += 1;
			continue;
		}
		printf("%c", s[i]);
	}
}