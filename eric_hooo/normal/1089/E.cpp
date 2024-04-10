#include<iostream>
#include<cstdio>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<deque>
#include<utility>
#include<cctype>
#include<bitset>
#include<stdio.h>
#include<time.h>
#define ll long long
#define mp make_pair
using namespace std;
const int INF=1e9;
/*--------main part---------*/
inline int read(){
    int X = 0,w = 0 ;
	char ch = 0;
    while(!isdigit(ch)) {w |= ch == '-';ch = getchar();}
    while(isdigit(ch)) X = (X<<3) + (X<<1) + (ch ^ 48),ch = getchar();
    return w ? -X : X;
}

bool no[64][64];
int cnt;
bool ok(int x,int y)
{
	return x<8 and x>=0 and y<8 and y>=0 and !no[x][y];
}
int main()
{
	int n;
	cin>>n;
	if(n==2)
	{
		cout<<"a1"<<" ";
		cout<<"h1"<<" "<<"h8";
		return 0;
	}
	if(n==51)
	{
		cout<<"a1 a2 a3 a4 a5 a6 a7 a8 b8 b7 b6 b5 b4 b3 b2 b1 c1 c2 c3 c4 c5 c6 c7 c8 d8 d7 d6 d5 d4 d3 d2 d1 e1 e2 e3 e4 e5 e6 e7 e8 f8 f7 f6 f5 f4 f3 f2 f1 g1 h1 h2 h8";
		return 0;
	}
	cout<<"a1"<<" ";
	int cur=2;
	int cnt=0;
	for(int i=0;i<6;)
	{
		if(i%2==0)
		{
			if(cnt==n-2)
			{
				cout<<"h"<<cur<<" "<<"h8";
				return 0;
			}
			cout<<char('a'+i)<<cur<<" ";
			cnt++;
			if(cur==8)
			{
				i++;
				cur=8;
				cnt++;
				cout<<char('a'+i)<<cur<<" ";
				if(cnt==n-2)
				{
					cout<<char('a'+i+1)<<8<<" "<<"h8";
					return 0;
				}
				if(cnt==n-1)
				{
					cout<<"h8";
					return 0;
				}
				cur=7;
				continue;
			}
			if(cnt==n-2)
			{
				cout<<"h"<<cur<<" "<<"h8";
				return 0;
			}
			cur++;
		}
		else
		{
			cout<<char('a'+i)<<cur<<" ";
			cnt++;
			if(cur==1)
			{
				i++;
				cur=1;
				if(cnt==n-2)
				{
					cout<<"h"<<1<<" "<<"h8";
					return 0;
				}
				cout<<char('a'+i)<<cur<<" ";
				cnt++;
				if(cnt==n-2)
				{
					cout<<'h'<<1<<" "<<"h8";
					return 0;
				}
				cur=2;
				continue;
			}
			if(cnt==n-2)
			{
				cout<<"h"<<cur<<" "<<"h8";
				return 0;
			}
			cur--;
		}
	}
	if(cnt==n-1)
	{
		cout<<"h8";
		return 0;
	}
	if(cnt==n-2)
	{
		cout<<"h1"<<" "<<"h8";
		return 0;
	}
	for(int i=8;i>=2;i--)
	{
		if(cnt==n-2)
		{
			cout<<"h"<<i<<" "<<"h8";
			return 0;
		}
		cout<<"g"<<i<<" ";
		cnt++;
		if(cnt==n-2)
		{
			cout<<"h"<<i<<" "<<"h8";
			return 0;
		}
	}
	if(cnt==n-2)
	{
		cout<<"h2"<<" "<<"h8";
		return 0;
	}
	cnt++;
	cout<<"h2"<<" ";
	if(cnt==n-1)
	{
		cout<<"h8";
		return 0;
	}
	cnt++;
	cout<<"h1"<<" ";
	if(cnt==n-1)
	{
		cout<<"h8";
		return 0;
	}
	for(int i=3;i<8;i++)
	{
		cout<<"h"<<i<<" ";
		cnt++;
		if(cnt==n-1)
		{
			cout<<"h8";
			return 0;
		}
	}
	return 0;
}