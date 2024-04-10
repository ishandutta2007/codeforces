#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,x,y,sum;
string st;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>x>>y;
	if (x>y) x=y;
	cin>>st;
	if (st[0]=='0') sum++;
	for (int i=1;i<st.length();i++){
		if (st[i-1]=='1'&&st[i]=='0') sum++;
	}
	if (sum==0) cout<<"0"<<endl;
	else cout<<x*(sum-1)+y<<endl;
	return 0;
}