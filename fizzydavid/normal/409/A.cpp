#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<ctime>
#include<utility>
#include<vector>
using namespace std; 
int w1,w2;
string s1,s2;
int main()
{
	cin>>s1>>s2;
	for(int i=0;i<s1.size();i+=2)
	{
		int a1,a2;
		if(s1[i]=='8'&&s1[i+1]=='<')a1=1;
		else if(s1[i]=='['&&s1[i+1]==']')a1=2;
		else a1=3;
		if(s2[i]=='8'&&s2[i+1]=='<')a2=1;
		else if(s2[i]=='['&&s2[i+1]==']')a2=2;
		else a2=3;
		if(a1==a2-1||a1==3&&a2==1)w1++;
		else if(a2==a1-1||a2==3&&a1==1)w2++;
	}
	if(w1>w2)cout<<"TEAM 1 WINS";else if(w1<w2)cout<<"TEAM 2 WINS";else cout<<"TIE";
 	return 0;
}