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
string s;
int main()
{
	cin>>s;
	if(s[0]>=97 && s[0]<=122)s[0]=char(s[0]-32);
	cout<<s;
	return 0;
}