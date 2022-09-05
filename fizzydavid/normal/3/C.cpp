/*
	Author  : JZdavid
	From    : CF
	Problem : 3C(dfs)
	Time    : 2014/8/7
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
map<string,string>m;
bool win(string s,char c)
{
	for(int i=0;i<3;i++)if(s[i*3]==c&&s[i*3+1]==c&&s[i*3+2]==c)return 1;
	for(int i=0;i<3;i++)if(s[i]==c&&s[3+i]==c&&s[6+i]==c)return 1;
	if(s[0]==c&&s[4]==c&&s[8]==c)return 1;
	if(s[2]==c&&s[4]==c&&s[6]==c)return 1;
	return 0;
}
string str=".........";
void dfs(int step)
{
	if(win(str,'X')){m[str]="the first player won";return;}
	else if(win(str,'0')){m[str]="the second player won";return;}
	else if(step==9){m[str]="draw";return;}
	if(step&1)m[str]="second";
	else m[str]="first";
	for(int i=0;i<9;i++)
	{
		if(str[i]!='.')continue;
		str[i]=step&1?'0':'X';
		dfs(step+1);
		str[i]='.';
	}
} 
int main()
{
	ios::sync_with_stdio(false);
	dfs(0);
	string s,t;
    for(int i=0;i<3;i++){cin>>t;s+= t;}
    if(m.find(s)==m.end()) cout<<"illegal"<<endl;
    else cout<<m[s]<<endl;
	return 0;
}