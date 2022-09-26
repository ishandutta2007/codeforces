#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 200020
const ll inf=0x3f3f3f3f3f3f3f3fll;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,m,A,B,x,y,_a[N],_b[N],g,dis[N];
ll ans,s[N];
vector<int> a[N],b[N];
int exgcd(int a,int b,int &x,int &y){
	if(b==0)return x=1,y=0,a;
	int g=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return g;
}
bool cmp(int i,int j){
	return s[i]==s[j]?i<j:s[i]<s[j];
}
ll Solve(int m,int n,int x,vector<int> &a,vector<int> &b){
	if((int)a.size()==m)return -1;
	static int tot,p[N];
	tot=0;
	for(int i=0;i<(int)a.size();++i){
		dis[++tot]=a[i];
		s[tot]=1LL*a[i]*x%m;
		p[tot]=tot;
	}
	for(int i=0;i<(int)b.size();++i){
		dis[++tot]=b[i];
		s[tot]=1LL*b[i]*x%m;
		p[tot]=tot;
	}
	sort(p+1,p+tot+1,cmp);
	p[0]=0,p[tot+1]=tot+1;
	s[0]=s[p[tot]]-m,s[tot+1]=s[p[1]]+m;
	ll mn=inf,ans=0;
	for(int i=1;i<=tot;++i){
		mn=min(mn+1LL*n*(s[p[i]]-s[p[i-1]]),1LL*dis[p[i]]);
		if(s[p[i]]==s[p[i+1]]||(s[p[i]]+1==s[p[i+1]]&&p[i]<=(int)a.size()))continue;
		ans=max(ans,mn+n*(s[p[i+1]]-s[p[i]]-1));
	}
	return ans;
}
int main(){
//	freopen("epidemic.in","r",stdin);
//	freopen("epidemic.out","w",stdout);
	n=read(),m=read();
	A=read();
	for(int i=0;i<A;++i){
		_a[i]=read();
	}
	B=read();
	for(int i=0;i<B;++i){
		_b[i]=read();
	}
	int g=exgcd(m,n,x,y);
	if(g>A+B){
		printf("-1\n");return 0;
	}
	x=(x%n+n)%n,y=(y%m+m)%m;
	for(int i=0;i<A;++i){
		a[_a[i]%g].push_back(_a[i]/g);
	}
	for(int i=0;i<B;++i){
		b[_b[i]%g].push_back(_b[i]/g);
	}
	for(int i=0;i<g;++i){
		if(a[i].empty()&&b[i].empty()){
			printf("-1\n");return 0;
		}
		ans=max(ans,Solve(n/g,m/g,x,a[i],b[i])*g+i);
		ans=max(ans,Solve(m/g,n/g,y,b[i],a[i])*g+i);
	}
	printf("%lld\n",ans);
	return 0;
}