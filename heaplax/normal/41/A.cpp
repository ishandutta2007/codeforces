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
string a,b;
int main()
{
	cin>>a>>b;
	reverse(a.begin(), a.end());
	if(a==b)printf("YES\n");
	else printf("NO\n");
	return 0; 
}