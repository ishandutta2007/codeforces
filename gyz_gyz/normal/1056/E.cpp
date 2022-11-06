#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 2000000
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
string s,t;int n,m,s0,s1;
int rk[N],sa[N],ct[N],rs[N],lcp[N][20];
bool cmp(int x,int y){return s[x]<s[y];}
bool eq(int x,int y){return x>=0&&y>=0&&x<n&&y<n&&s[x]==s[y];}
void init(int m){
	rep(i,1,n)sa[i]=i-1;sort(sa+1,sa+n+1,cmp);rk[sa[1]]=1;
	rep(i,2,n)rk[sa[i]]=rk[sa[i-1]]+(s[sa[i]]!=s[sa[i-1]]);
	for(int i=1;i<n;i<<=1){
		rep(j,1,i)rs[j]=n-j;int tot=i;
		rep(j,1,n)if(sa[j]>=i)rs[++tot]=sa[j]-i;
		rep(j,0,n)ct[j]=0;
		rep(j,0,n-1)++ct[rk[j]];
		rep(j,1,n)ct[j]+=ct[j-1];
		dep(j,n,1)sa[ct[rk[rs[j]]]--]=rs[j];
		rep(j,2,n)rs[j]=rk[sa[j]]!=rk[sa[j-1]]||rk[sa[j]+i]!=rk[sa[j-1]+i];
		rk[sa[1]]=1;rep(j,2,n)rk[sa[j]]=rk[sa[j-1]]+rs[j];
	}
	rep(i,0,n-1){int *x=&lcp[rk[i]][0];
		if(i&&lcp[rk[i-1]][0])*x=lcp[rk[i-1]][0]-1;else *x=0;
		if(rk[i]>1)while(eq(sa[rk[i]-1]+*x,i+*x))++*x;
	}
	rep(j,0,m-1)rep(i,1,n)
		if((n-i)>>j)lcp[i][j+1]=min(lcp[i][j],lcp[i+(1<<j)][j]);
		else lcp[i][j+1]=lcp[i][j];
}
int qs(int l,int r){
	if(l==r)return n-l;l=rk[l]+1;r=rk[r]+1;
	if(l>r)swap(l,r);int t=31-clz(r-l);
	return min(lcp[l][t],lcp[r-(1<<t)][t]);
}
bool ck(int i0,int i1){
	if(!i1)return 0;
	if(i0==i1)rep(i,1,m-1)if(t[i]!=t[0]){
		if(qs(0,i*i0)>=i0)return 0;break;
	}int x=0,r0=-1,r1=-1;
	rep(i,0,m-1)if(t[i]=='0'){
		if(r0==-1)r0=x;
		else if(qs(r0,x)<i0)return 0;x+=i0;
	}else{
		if(r1==-1)r1=x;
		else if(qs(r1,x)<i1)return 0;x+=i1;
	}return 1;
}
int main(){
	cin>>t;cin>>s;int ans=0;
	n=s.length();m=t.length();init(31-clz(n));
	rep(i,0,m-1)if(t[i]=='1')s1++;else s0++;
	rep(i0,1,n/s0)if(!((n-i0*s0)%s1)&&ck(i0,(n-i0*s0)/s1))ans++;
	printf("%d\n",ans);
}