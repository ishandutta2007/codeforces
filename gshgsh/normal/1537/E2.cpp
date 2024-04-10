#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 2000001
int N,M,K,a[MAXN],nxt[MAXN],tmp[MAXN],sa[MAXN],rk[MAXN],cnt[MAXN];
bool check(int x){return rk[x]>rk[1];}
int main()
{
	cin>>N>>K;For(i,1,N){char c;cin>>c;a[i]=c-'a';rk[i]=a[i]+1;sa[i]=i;}M=26;
	for(int k=1;k<=N;k<<=1)
	{
		For(i,1,N)tmp[i]=sa[i];For(i,1,M)cnt[i]=0;For(i,1,N)cnt[rk[tmp[i]+k]]++;For(i,1,M)cnt[i]+=cnt[i-1];FOR(i,N,1)sa[cnt[rk[tmp[i]+k]]--]=tmp[i];
		For(i,1,N)tmp[i]=sa[i];For(i,1,M)cnt[i]=0;For(i,1,N)cnt[rk[tmp[i]]]++;For(i,1,M)cnt[i]+=cnt[i-1];FOR(i,N,1)sa[cnt[rk[tmp[i]]]--]=tmp[i];
		M=0;For(i,1,N)tmp[i]=rk[i];For(i,1,N)rk[sa[i]]=M+=tmp[sa[i]]!=tmp[sa[i-1]]||tmp[sa[i]+k]!=tmp[sa[i-1]+k];if(M==N)break;
	}
	int j=0;For(i,2,N){while(j&&a[i]!=a[j+1])j=nxt[j];if(a[i]==a[j+1])j++;nxt[i]=j;}
	int x=N-nxt[N];For(i,2,N)if(check(i)){x=i-1;break;}For(i,1,K)cout<<char(a[(i-1)%x+1]+'a');cout<<endl;return 0;
}