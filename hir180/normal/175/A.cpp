//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
//HIR180
//IOI2014N
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
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
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int main()
{
	srand((unsigned int)time(NULL));
	string str;
	cin >> str;
	//0~i
	//i+1~j
	//j+1~end
	int res=-1;
	for(int i=0;i<str.size();i++)
	{
		for(int j=i+1;j<str.size();j++)
		{
			for(int k=j+1;k<str.size();k++)
			{
				int tot=0,tot2=0,tot3=0;
				if(i+1>=2 && str[0]=='0') goto out;
				if(j-i>=2 && str[i+1]=='0') goto out;
				if(str.size()-1-j>=2 && str[j+1]=='0') goto out;
				for(int x=0;x<=i;x++)
				{
					tot=(tot*10+str[x]-'0');
					if(tot>1000000) goto out;
				}
				for(int x=i+1;x<=j;x++)
				{
					tot2=(tot2*10+str[x]-'0');
					if(tot2>1000000) goto out;
				}
				for(int x=j+1;x<str.size();x++)
				{
					tot3=(tot3*10+str[x]-'0');
					if(tot3>1000000) goto out;
				}
				res=max(res,tot+tot2+tot3);
				out:;
			}
		}
	}
	cout << res << endl;
}