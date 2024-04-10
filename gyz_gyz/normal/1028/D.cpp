#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 500000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define Pi acos(-1.)
#define eps 1e-8
using namespace std;
int n,tot;bool u;ll nw,ans,x,l,r,w[N];
set<ll>s1,s2;char str[9];
int main(){
	scanf("%d",&n);nw=1;
	rep(i,1,n){
		scanf("%s",str);scanf("%I64d",&x);
		if(str[1]=='D')w[++tot]=x;else{u=0;
			rep(i,1,tot)if(w[i]==x){u=1;break;}
			if(!u){
				if((!s1.empty())&&(*(--s1.end())==x))s1.erase(--s1.end());
				else if((!s2.empty())&&(*s2.begin()==x))s2.erase(s2.begin());
				else{printf("0");return 0;}
			}else nw=nw*2%mo;
			rep(i,1,tot){
				if(w[i]<x)s1.insert(w[i]);
				if(w[i]>x)s2.insert(w[i]);
			}tot=0;
		}
	}
	if(!s1.empty())l=*(--s1.end());ans=nw;
	if(!s2.empty())r=*(s2.begin());else r=Inf;
	rep(i,1,tot)if((w[i]>l)&&(w[i]<r))add(ans,nw);
	printf("%I64d\n",ans);
}