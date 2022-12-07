#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
long long n,ans;
bool ok=true;
int main()
{
	cin>>n;
	while(n>0)
	{
		if(n%10==4 || n%10==7)ans++;
		n/=10;
	}
	if(ans==0)ok=false;
	while(ans>0)
	{
		if(ans%10!=4 && ans%10!=7)ok=false;
		ans/=10;
	}
	if(ok)cout<<"YES";
	else cout<<"NO";
	return 0;
}