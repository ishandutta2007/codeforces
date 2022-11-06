#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define abs(x) ((x)<0?-(x):(x))
#define N 100000
#define M 301
#define ll long long
#define inf 1000000000
using namespace std;
map<string,int>mp;string str;
int n,m,tot,L,s,ans,u,a[N][M],l[M],id[M],w[N],p[N],ed[N];
int main(){
	scanf("%d",&n);L=-1;
	rep(i,1,n){
		cin>>str;l[i]=str.length();u=mp[str];
		if(!u)mp[str]=u=++m;id[i]=u;L+=l[i]+1;
	}
	rep(i,1,n){s=0;
		rep(j,i,n){
			if(!a[s][id[j]]){
				w[++tot]=w[s]+l[j]-(s==0);
				a[s][id[j]]=tot;
			}
			s=a[s][id[j]];
			if(ed[s]<i)ed[s]=j,p[s]++;
		}
	}
	rep(i,1,tot)if((p[i]>1)&&(w[i]*p[i]>ans))
		ans=w[i]*p[i];
	printf("%d\n",L-ans);
}