#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<deque>
#include<cmath>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
#define MAXB 501
int N,M,B,K,l[MAXB],r[MAXB],a[MAXN],cnt[MAXB][MAXN],lst;deque<int>q[MAXB];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void ssh(int x,int y)
{
	int xB=(x-1)/B+1,yB=(y-1)/B+1;
	if(xB==yB){int a=x-l[xB],b=y-l[xB],tmp=q[xB][b];FOR(i,b,a+1)q[xB][i]=q[xB][i-1];q[xB][a]=tmp;return;}
	vector<int>tmp;For(i,1,r[xB]-x+1)tmp.push_back(q[xB].back()),q[xB].pop_back();
	vector<int>tmp2;For(i,1,y-l[yB])tmp2.push_back(q[yB].front()),q[yB].pop_front();
	q[xB].push_back(q[yB].front());cnt[xB][q[xB].back()]++;cnt[yB][q[yB].front()]--;q[yB].pop_front();
	while(!tmp.empty())q[xB].push_back(tmp.back()),tmp.pop_back();
	while(!tmp2.empty())q[yB].push_front(tmp2.back()),tmp2.pop_back();
	For(i,xB,yB-1)q[i+1].push_front(q[i].back()),q[i].pop_back(),cnt[i][q[i+1].front()]--,cnt[i+1][q[i+1].front()]++;
}
int ask(int x,int y,int k)
{
	int xB=(x-1)/B+1,yB=(y-1)/B+1;
	if(xB==yB){int a=x-l[xB],b=y-l[xB],ans=0;For(i,a,b)ans+=q[xB][i]==k;return ans;}
	int ans=0;For(i,x-l[xB],r[xB]-l[xB])ans+=q[xB][i]==k;For(i,0,y-l[yB])ans+=q[yB][i]==k;For(i,xB+1,yB-1)ans+=cnt[i][k];return ans;
}
int main()
{
	N=get();For(i,1,N)a[i]=get();B=sqrt(N);while(r[K]<N)K++,l[K]=r[K-1]+1,r[K]=min(N,B*K);
	For(i,1,K)For(j,l[i],r[i])q[i].push_back(a[j]),cnt[i][a[j]]++;M=get();
	For(i,1,M)
	{
		int opt=get(),l=(get()+lst-1)%N+1,r=(get()+lst-1)%N+1;if(l>r)swap(l,r);
		if(opt==1)ssh(l,r);else cout<<(lst=ask(l,r,(get()+lst-1)%N+1))<<'\n';
	}
	return 0;
}