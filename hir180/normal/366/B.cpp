#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int n,k;
int val[100005]={};
int main()
{
	cin >> n >> k;
	for(int i=0;i<n;i++)
	{
		int x;
		cin >> x;
		val[i%k]+=x;
	}
	int mi=1000000000;
	int idx;
	for(int i=0;i<k;i++)
	{
		if(mi>val[i]) { idx=i+1; mi=val[i];}
	}
	cout << idx << endl;
}