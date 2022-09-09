#include<bits/stdc++.h>
#define maxn 240000 
using namespace std;
char s[maxn];
stack<int> sta;
int match[maxn];
bool dete[maxn]; 
int main(){
	int n, k;
	scanf("%d %d %s", &n, &k, s);
	for(int i = 0; i < n; i += 1){
		if(s[i] == '(') sta.push(i);
		else{
			int p = sta.top();
			match[p] = i;
			sta.pop();
		}
	}
	int cnt = (n - k) / 2;
	for(int i = 0; i < n && cnt; i += 1){
		if(s[i] == '('){
			dete[i] = true;
			dete[match[i]] = true;
			cnt -= 1;
		}
	}
	for(int i = 0; i < n; i += 1)
		if(dete[i] == false) printf("%c", s[i]);
}