#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
int main(){
	string str;
	cin >> str;
	int s=str.size();
	bool used[10]={};
	for(int i=0;i<s;i++)
	{
		if(str[i]-'A'>=0 && str[i]-'A'<10)
		{
			used[str[i]-'A']=true;
		}
	}
	int acc=0;
	for(int i=0;i<10;i++) acc+=used[i];
	bool top=false;
	if(str[0]-'A'>=0 && str[0]-'A'<10) top=true;
	long long ans=1;
	for(int i=0;i<acc;i++)
	{
		if(top && !i) ans*=9LL;
		else ans*=1LL*(10-i);
	}
	int r=0;
	bool topp=false;
	if(str[0]=='?') topp=true;
	for(int i=0;i<s;i++) r+=(str[i]=='?');
	while(r--) ans*=10LL;
	if(topp) ans=ans/10*9;
	cout << ans << endl;
}