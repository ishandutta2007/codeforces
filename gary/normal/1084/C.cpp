#include<bits/stdc++.h>
#define ll long long
const int mod = 1e9 + 7;
using namespace std;
 
int main()
{
	string str;
	ll ans = 0;
	cin>>str;
	str += 'b';
	int len = str.length();
	ans = 1;
	ll num1 = 1;
	for(int i = 0; i < len; i++){
		if(str[i] == 'a') num1++;
		else if(str[i] == 'b'){
			ans = ans * num1 % mod;
			num1 = 1;
		}
	}
	ans -= 1;
	cout << ans << endl;
}