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
string s1,s2;
set<int>lt[26];
bool f;
int main()
{
	cin>>s1>>s2;
	for(int i=0;i<s1.size();i++)lt[s1[i]-'a'].insert(i);
	int p=-1,cnt=1;
	for(int i=0;i<s2.size();i++)
	{
		if(lt[s2[i]-'a'].empty()){f=1;}
		if(f==1)break;
		if(lt[s2[i]-'a'].end()==lt[s2[i]-'a'].upper_bound(p))p=-1,cnt++;
		p=*lt[s2[i]-'a'].upper_bound(p);
	}
	if(f)cout<<"-1";else cout<<cnt;
// 	system("pause");
	return 0;
}