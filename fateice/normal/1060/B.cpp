#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
L n;
inline L calc(L n)
{
    if(n<10)
      return n;
    if(n%10==9)
      return 9+calc(n/10);
    return n%10+10+calc(n/10-1);
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	cout<<calc(n);
	return 0;
}