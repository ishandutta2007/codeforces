#include<bits/stdc++.h>
#define maxn 120000
using namespace std;
typedef long long LL;
char s[maxn]; 
struct seq{
	char type;
	int cnt;
}now;
void print(int n){
	cout << n;
	exit(0);
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n >> s;
	vector<seq> v; 
	for(int i = 0; i <= n; i += 1){
		if(s[i] == now.type) now.cnt += 1;
		if(s[i] != now.type){
			if(i) v.push_back(now);
			now.type = s[i];
			now.cnt = 1;
		}
	}
	int G = 0;
	for(seq p : v) if(p.type == 'G') G += 1;
	if(G == 0) print(0);
	if(G == 1) for(seq p : v) if(p.type == 'G') print(p.cnt);
	int ans = 0;
	for(int i = 0; i < v.size(); i += 1)
		if(v[i].type == 'G'){
			ans = max(ans, v[i].cnt + 1);
			if(i + 2 < v.size() && v[i + 1].cnt == 1) ans = max(ans, v[i].cnt + v[i + 2].cnt + (G > 2));
		}
	print(ans);
}