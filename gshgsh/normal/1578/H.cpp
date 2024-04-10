#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1000001
int N,M,p[MAXN];string a[MAXN];
void qsort(int l,int r,int step)
{
	if(l>r||step==M)return;vector<int>q[26];For(i,l,r)q[a[p[i]][step]-'A'].push_back(p[i]);
	if(step&1){int now=l;FOR(i,25,0){for(auto j:q[i])p[now++]=j;qsort(l,now-1,step+1);l=now;}}
	else{int now=l;For(i,0,25){for(auto j:q[i])p[now++]=j;qsort(l,now-1,step+1);l=now;}}
}
int main()
{
	cin>>N>>M;For(i,1,N)cin>>a[i],p[i]=i;qsort(1,N,0);For(i,1,N)cout<<p[i]<<" \n"[i==N];
}