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
#define N 3010
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,m,y,nw,a[N],nt[N],fr[N];
int w[N][N],s[N];ll b[N],ans,x,fi;
bool cmp(int x,int y){
	if(!x)return 1;
	return (b[x]>b[y])||((b[x]==b[y])&&(x>y));
}
void ct(int x){
	nt[fr[x]]=nt[x];
	if(nt[x])fr[nt[x]]=fr[x];
}
int main(){
	scanf("%d%d",&n,&m);ans=Inf;
	rep(i,1,n){
		scanf("%d%I64d",&a[i],&b[i]);
		if(a[i]>1)w[a[i]][++s[a[i]]]=i;
	}
	rep(i,2,m)if(s[i])sort(w[i]+1,w[i]+s[i]+1,cmp);
	rep(i,1,n){
		rep(j,1,n)if(cmp(j,i)&&cmp(nt[i],j))nt[i]=j;
		if(nt[i])fr[nt[i]]=i;
	}
	rep(i,1,n)if(!fr[i])nt[0]=i;
	rep(i,1,n)if(a[i]==1){ct(i);nw++;}
	rep(i,2,m)while(s[i]>(n+1)/2){
		fi+=b[w[i][s[i]]];ct(w[i][s[i]--]);nw++;
	}
	dep(i,(n+1)/2,1){
		rep(j,2,m)if(s[j]==i){
			fi+=b[w[j][s[j]]];ct(w[j][s[j]--]);nw++;
		}
		x=0;y=nt[0];
		rep(j,nw+1,i)x+=b[y],y=nt[y];
		if(fi+x<ans)ans=fi+x;
		if(!x)break;
	}
	printf("%I64d\n",ans);
}