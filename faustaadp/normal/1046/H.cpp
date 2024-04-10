#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
unordered_map<ll,ll> d;
ll n,i,j,a[28],tem,has;
string s;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
    {
        for(j=0;j<26;j++)
            a[j]=0;
        cin>>s;
        for(j=0;j<s.length();j++)
            a[s[j]-'a']=1-a[s[j]-'a'];
        ll tem=0;
        for(j=0;j<26;j++)
            if(a[j])tem+=(1<<j);
        has+=d[tem];
        for(j=0;j<26;j++)
            has+=d[(tem^(1<<j))];
        d[tem]++;
    }
    cout<<has<<"\n";
}