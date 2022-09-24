#include<bits/stdc++.h>
using namespace std;
void Solve(){
	string s;
	cin>>s;
	int sum[3]={0};
	for(auto i:s)sum[i-'A']++;
	if(sum[0]+sum[2]==sum[1])puts("YES");
	else puts("NO");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}