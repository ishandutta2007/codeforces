//while(true)rp++;
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
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
#define last asdfasdf
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
string s;
int num[100111],last,cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(')num[i]=(i>0?num[i-1]:0)+1;
		else num[i]=(i>0?num[i-1]:0)-1;
		if(num[i]<0)
		{
			cout<<"-1"<<endl;
			return 0;
		}
		if(s[i]=='#')last=i,cnt++;
	}
	int tmp=INF;
	for(int i=last;i<s.size();i++)tmp=min(tmp,num[i]);
	if(tmp<num[s.size()-1])
	{
		cout<<"-1"<<endl;
		return 0;
	}
	while(--cnt)cout<<"1"<<endl;
	cout<<1+num[s.size()-1]<<endl;
	return 0;
}