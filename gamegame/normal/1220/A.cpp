#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200001];
int cnt[226];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	string s;cin >> s;
	for(auto c:s) cnt[c]++;
	for(int i=0; i<cnt['n'] ;i++) cout << "1 ";
	for(int i=0; i<cnt['z'] ;i++) cout << "0 ";
}