#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P1 998244853
#define P2 100000007
#define MAXN 1000001
int N,M,a[MAXN],b[MAXN],pw1[MAXN],Hash1[MAXN],pw2[MAXN],Hash2[MAXN];
int HASH1(int l,int r){return (Hash1[r]-1ll*Hash1[l-1]*pw1[r-l+1]%P1+P1)%P1;}
int HASH2(int l,int r){return (Hash2[r]-1ll*Hash2[l-1]*pw2[r-l+1]%P2+P2)%P2;}
bool check(int l1,int r1,int l2,int r2){return HASH1(l1,r1)==HASH1(l2,r2)&&HASH2(l1,r1)==HASH2(l2,r2);}
int main()
{
	string s,t;cin>>s>>t;N=s.length(),M=t.length();For(i,1,N)a[i]=s[i-1]-'0';For(i,1,M)b[i]=t[i-1]-'a';
	pw1[0]=pw2[0]=1;For(i,1,M)pw1[i]=27ll*pw1[i-1]%P1,pw2[i]=27ll*pw2[i-1]%P2,Hash1[i]=(27ll*Hash1[i-1]+b[i]+1)%P1,Hash2[i]=(27ll*Hash2[i-1]+b[i]+1)%P2;
	int cnt[2]={0,0};if(a[1])For(i,1,N)a[i]^=1;For(i,1,N)cnt[a[i]]++;int ans=0;
	For(i,1,M/cnt[0])
	{
		int x=M-i*cnt[0];if(!x||x%cnt[1])continue;int len[2]={i,x/cnt[1]},pos[2]={0,0};int now=0;bool flag=1;
		For(j,1,N){if(!pos[a[j]])pos[a[j]]=now+1,now+=len[a[j]];else if(check(pos[a[j]],pos[a[j]]+len[a[j]]-1,now+1,now+len[a[j]]))now+=len[a[j]];else {flag=0;break;}}
		if(check(pos[0],pos[0]+len[0]-1,pos[1],pos[1]+len[1]-1))flag=0;ans+=flag;
	}
	cout<<ans<<'\n';return 0;
}