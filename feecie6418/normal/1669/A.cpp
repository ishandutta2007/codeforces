#include<bits/stdc++.h>
using namespace std;
void Solve(){
	int x;
	cin>>x;
	if(x<=1399)puts("Division 4");
	else if(x<=1599)puts("Division 3");
	else if(x<=1899)puts("Division 2");
	else puts("Division 1");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}