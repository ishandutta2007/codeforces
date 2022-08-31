#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	char a;
	int b;
	cin >> a >> b;
	int ans=8;
	if(a=='a' || a=='h') ans-=3;
	if(b==1 || b==8) ans-=3;
	if(ans==2) ans=3;
	cout << ans;
}