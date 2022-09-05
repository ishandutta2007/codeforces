#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
int a1,a2,a3,b1,b2,b3,n; 
int main()
{
	cin>>a1>>a2>>a3>>b1>>b2>>b3>>n;
	int s1=a1+a2+a3;
	int s2=b1+b2+b3;
	if((s1+4)/5+(s2+9)/10<=n)puts("YES");else puts("NO");
// 	system("pause");
	return 0;
}