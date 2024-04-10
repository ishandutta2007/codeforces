//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
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
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
int main(){
	string s;
	cin >> s;
	long long ret=1LL;
	bool len=false;
	ll curlen=0;
	s.pb('9');

	for(int i=0;i<s.size()-1;i++)
	{
		if(s[i]-'0'+s[i+1]-'0'==9)
		{
			if(len)
			{
				curlen++;
			}
			else
			{
				curlen=1LL;
				len=true;
			}
		}
		else
		{
			if(len)
			{
				if(curlen%2==0) ret*=((curlen+2LL)/2LL);
			}
			len=false;
			curlen=0LL;
		}
	}
	printf("%lld\n",ret);
}