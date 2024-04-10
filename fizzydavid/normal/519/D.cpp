//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
typedef unsigned long long ull;
struct Hash
{
	ll *val;
	ull *key;
	int size,mask;
	void clear()
	{
		memset(val,0,size*sizeof(ll));
		memset(key,0,size*sizeof(ull));
	}
	void init(int sz)
	{
		size=1;
		while(size<=sz)size=size*2;
		mask=size-1;
		val=new ll[size];
		key=new ull[size];
		clear();
	}
	ll& operator[](ull id)
	{
		ull p=(id*98765+id/12345*67890)&mask;
		for(;val[p]!=0&&key[p]!=id;p=(p+1)&mask);
		key[p]=id;
		return val[p];
	}
}h;
ll w[256];
string s;
int main()
{
	ios::sync_with_stdio(false);
	h.init(500000);
	for(int i='a';i<='z';i++)cin>>w[i];
	cin>>s;
	ll sum,ans=0;
	for(int k='a';k<='z';k++)
	{
		h.clear();sum=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]==k)ans+=h[sum];
			sum+=w[s[i]];
			if(s[i]==k)h[sum]++;
		}
	}
	cout<<ans<<endl;
	return 0;
}