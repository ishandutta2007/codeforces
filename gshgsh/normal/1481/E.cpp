#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 500001
int N,a[MAXN],l[MAXN],r[MAXN],cnt[MAXN],tot[MAXN],f[MAXN];
int main()
{
	cin>>N;For(i,1,N)cin>>a[i],!l[a[i]]?l[a[i]]=i:0,tot[a[i]]++;FOR(i,N,1)!r[a[i]]?r[a[i]]=i:0;
	FOR(i,N,1)cnt[a[i]]++,f[i]=max(f[i+1],i==l[a[i]]?tot[a[i]]+f[r[a[i]]+1]:cnt[a[i]]);cout<<N-f[1]<<endl;return 0;
}