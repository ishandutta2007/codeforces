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
int n,k,v[30];
long long res;
string a;
int main()
{
	cin>>a>>k;
	n=a.size();
	for(int i=1;i<=26;i++)
	{
		cin>>v[i];
	}
	for(int i=0;i<n;i++)
	{
		res+=v[a[i]-'a'+1]*(i+1);
	}
	sort(v+1,v+27);
	res+=(n+1+n+k)*k/2*v[26];
	cout<<res;
// 	system("pause");
	return 0;
}