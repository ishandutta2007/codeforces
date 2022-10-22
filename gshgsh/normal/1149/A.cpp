#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
int N,cnt[3];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get();For(i,1,N)cnt[get()]++;
	if(!cnt[1]){For(i,1,N)cout<<2<<" \n"[i==N];return 0;}if(!cnt[2]){For(i,1,N)cout<<1<<" \n"[i==N];return 0;}
	cout<<"2 1 ";For(i,1,cnt[2]-1)cout<<2<<' ';For(i,1,cnt[1]-1)cout<<1<<' ';cout<<'\n';return 0;
}