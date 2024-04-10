/*
	Author  : JZdavid
	From    : CF
	Problem : 185B Mushroom Scientists
	Time    : 2014/8/1
	Verdict : Accepting
*/
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
typedef long long ll;
const int INF=1<<28;
const long long LINF=1ll<<61;
int s,a,b,c;
int main()
{
	scanf("%d%d%d%d",&s,&a,&b,&c);
	if(a+b+c==0)printf("%d 0 0",s);
	else printf("%.10lf %.10lf %.10lf",1.0*a*s/(a+b+c),1.0*b*s/(a+b+c),1.0*c*s/(a+b+c));
// 	system("pause");
	return 0;
}