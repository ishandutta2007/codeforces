#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
int N;
int main()
{
	cin>>N;vector<int>bits;while(N)bits.push_back(N%10),N/=10;int now=1,ans=0;
	if(bits.back()==1){int x=1;For(i,1,bits.size()-1)x*=9;ans=x;}
	while(!bits.empty()){int x=bits.back();bits.pop_back();if(x){int y=now*(x-1);For(k,1,(int)bits.size())y*=9;ans=max(ans,y);}now*=x;}
	cout<<max(ans,now)<<'\n';return 0;
}