#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int N,a[MAXN],cnt[26];ll now,ans;
int main()
{
	cin>>N>>ans;For(i,1,N){char c;cin>>c;a[i]=c-'a';if(i<N-1)cnt[a[i]]++;i<N?now-=1<<a[i]:now+=1<<a[i];}
	if(ans<now||ans-now&1){cout<<"No\n";return 0;}ll del=ans-now>>1;For(i,0,24)if(cnt[i]>1)cnt[i+1]+=cnt[i]-1>>1,cnt[i]-=(cnt[i]-1>>1)<<1;
	FOR(i,25,0)while(cnt[i]&&del>=1<<i)cnt[i]--,del-=1<<i;cout<<(!del?"Yes\n":"No\n");return 0;
}