#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define MAXN 1000001 
ll k,l,r,t,x,y;bool vis[MAXN];
int main()
{
	cin>>k>>l>>r>>t>>x>>y;bool flag=1;
	if(x>=y){if(k+y>r)k-=x,t--;if(k<l)flag=0;if(x!=y&&(k-l)/(x-y)<t)flag=0;cout<<(flag?"Yes\n":"No\n");return 0;}
	while(t){if(vis[k%x])break;vis[k%x]=1;ll tmp=min(t,(k-l)/x);k-=tmp*x,t-=tmp;if(!t)break;t--;if(k+y<=r)k+=y;k-=x;if(k<l||k>r){flag=0;break;}}cout<<(flag?"Yes\n":"No\n");return 0;
}