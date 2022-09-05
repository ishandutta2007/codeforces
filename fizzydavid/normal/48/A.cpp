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
#define win(x,y) (x==y+1||x==0&&y==2)?1:0 
string s[3];
const char c[3]={'F','M','S'};
int n[3];
int main()
{
	cin>>s[0]>>s[1]>>s[2];
	for(int i=0;i<3;i++)
	{
		if(s[i]=="rock")n[i]=0;
		if(s[i]=="paper")n[i]=1;
		if(s[i]=="scissors")n[i]=2;
	}
	int cnt=0,winner=0;
	for(int i=0;i<=2;i++)for(int j=0;j<3;j++)if(win(n[i],n[j])){if(cnt==1&&winner!=i)cnt--;cnt++,winner=i;}
	if(cnt==2)cout<<c[winner];else cout<<"?";
// 	system("pause");
	return 0;
}