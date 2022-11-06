#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define gc getchar()
#define N 2000000
#define ll long long
#define inf 1000000000
#define mo 998244353
#define eps 1e-6
using namespace std;
int n,l[N],r[N],ty[N],s[N][2];
char ch[9];bool w[N];
bool cc(bool x,bool y,int z){
	if(z==1)return x&y;
	else if(z==2)return x|y;
	else return x^y;
}
void cal(int x){
	if(!ty[x])return;cal(l[x]);
	if(ty[x]==4)w[x]=w[l[x]]^1;else{
		cal(r[x]);w[x]=cc(w[l[x]],w[r[x]],ty[x]);
	}
}
void sol(int x){
	if(!ty[x])return;
	if(ty[x]==4){
		s[l[x]][0]=s[x][1];s[l[x]][1]=s[x][0];sol(l[x]);
	}else{
		s[l[x]][0]=s[x][cc(0,w[r[x]],ty[x])];
		s[l[x]][1]=s[x][cc(1,w[r[x]],ty[x])];
		s[r[x]][0]=s[x][cc(0,w[l[x]],ty[x])];
		s[r[x]][1]=s[x][cc(1,w[l[x]],ty[x])];
		sol(l[x]);sol(r[x]);
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%s",ch);
		if(ch[0]=='I')scanf("%d",&w[i]);
		else if(ch[0]=='N'){ty[i]=4;scanf("%d",&l[i]);}else{
			scanf("%d%d",&l[i],&r[i]);
			if(ch[0]=='A')ty[i]=1;
			if(ch[0]=='O')ty[i]=2;
			if(ch[0]=='X')ty[i]=3;
		}
	}
	cal(1);s[1][0]=0;s[1][1]=1;sol(1);
	rep(i,1,n)if(!ty[i])printf("%d",s[i][w[i]^1]);
}