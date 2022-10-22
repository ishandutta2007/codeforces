#include<iostream>
#include<vector>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define lowbit(x) x&-x
#define MAXN 200001
int N,a[MAXN],c[MAXN];ll ans;string s;vector<int>pos[26];
void upd(int x){for(int i=x;i;i-=lowbit(i))c[i]++;}int ask(int x){int ans=0;for(int i=x;i<=N;i+=lowbit(i))ans+=c[i];return ans;}
int main()
{
	cin>>N>>s;s=" "+s;For(i,1,N)pos[s[i]-'a'].push_back(i);For(i,0,25)For(j,0,int(pos[i].size()-1))a[pos[i][j]]=pos[i][pos[i].size()-1-j];For(i,1,N)a[i]=N+1-a[i];
	For(i,1,N)ans+=ask(a[i]),upd(a[i]);cout<<ans<<endl;return 0;
}