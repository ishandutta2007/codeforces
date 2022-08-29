#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
inline int gcd(re int x,re int y){return y?gcd(y,x%y):x;}
void exgcd(long long a,long long b,long long &x,long long &y){
    if(b==0){
        x=1; y=0;
        return ;
    }
    exgcd(b,a%b,x,y);
    long long tmp=x;
    x=y;
    y=tmp-a/b*y;
}
int n,m,T,a[200002],s,G,sum,ans[200002];
struct node{
	int x,y;
	bool operator <(const node A)const{return x==A.x?y>A.y:x<A.x;}
};
map<int,vector<node> >V;
vector<node>Q;
signed main(){
	T=read(),n=read();
	for(re int i=1;i<=n;++i)a[i]=read(),s+=a[i];
	G=gcd(s,T);re int gg=gcd(s,T);
	for(re int i=1;i<=n;++i){
		sum+=a[i],sum%=T;
		V[sum%G].push_back((node){sum,i});
	}
	G=T/G;
	for(auto z:V){
		re int x,y;Q.clear();
		exgcd(s%T,T,x,y);
		for(auto o:z.second){
			re int xx=x*(o.x-z.first);
			xx%=T,xx+=T,xx%=T,xx/=gg;
			Q.push_back((node){xx,o.y});
		}
		sort(Q.begin(),Q.end());
		for(re int i=0;i+1<Q.size();++i)ans[Q[i].y]=Q[i+1].x-Q[i].x;
		ans[Q[Q.size()-1].y]=Q[0].x+G-Q[Q.size()-1].x;
	}
	for(re int i=1;i<=n;++i)printf("%lld ",ans[i]);
}