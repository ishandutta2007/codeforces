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
int n,m,mn,mx;
int main()
{
	scanf("%d%d%d%d",&n,&m,&mn,&mx);
	int cnt=2;
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		if(x==mn||x==mx)cnt--;
		if(x<mn||x>mx){cnt=1000;break;}
	}
	if(n-m<cnt)cout<<"Incorrect";else cout<<"Correct";
// 	system("pause");
	return 0;
}