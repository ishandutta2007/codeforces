//source:
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
typedef long long ll;
const int INF=1<<28;
const long long LINF=1ll<<61;
ll n,k,cnt[26];
string s;
bool cmp(ll x,ll y){return x>y;}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k>>s;
	for(int i=0;i<s.size();i++)cnt[s[i]-'A']++;
	sort(cnt,cnt+26,cmp);
	ll ans=0,tmp=0;
	for(int i=0;i<26;i++)
	{
		if(tmp+cnt[i]>k)
		{
			ans+=(k-tmp)*(k-tmp);
			break;
		}
		else
		{
			ans+=cnt[i]*cnt[i];
		}
		tmp+=cnt[i];
	}
	cout<<ans;
	return 0;
}