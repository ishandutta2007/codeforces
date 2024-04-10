#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	ios::sync_with_stdio(false);
	string s;
	cin >> n >> s;
	int mn=0,mx=0;
	int cur=0;
	for(auto c:s){
		if(c=='L') mn--;
		else mx++;
		//mn=min(cur,mn);
		//mx=max(cur,mx);
	}
	cout << mx-mn+1 << endl;
}