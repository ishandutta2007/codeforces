#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,a,b) for(int i=(b),i##_end=(a);i>=i##_end;i--)
inline int rd() {
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=2e5+11,MX=29;
int n,a[N];
ll ans;
struct Node{int v;Node *s[2];}pl[N*33],*rt=pl,*cur=pl+1;
inline void ins(int w){
	Node*x=rt;
	per(i,0,MX){
		x->v++;int t=w>>i&1;
		if(!x->s[t])x->s[t]=cur++;
		x=x->s[t];
	}x->v++;
}
inline void del(int w){
	Node*x=rt;
	per(i,0,MX){
		x->v--;int t=w>>i&1;
		x=x->s[t];
	}x->v--;
}
inline int ask(int w){
	int r=0;Node*x=rt;
	per(i,0,MX){
		int t=w>>i&1;
		if(x->s[t]&&x->s[t]->v)x=x->s[t];
		else{
			x=x->s[t^1];
			r|=1<<i;
		}
	}
	return r;
}
void solve(int o,int l,int r){
//	cout<<o<<" "<<l<<" "<<r<<endl;
	if(l>=r||o<0)return;
	else{
		int m=r+1;
		rep(i,l,r) {
			if((a[i]>>o)&1){
				m=i;
				break;
			}
		}
		solve(o-1,l,m-1),solve(o-1,m,r);
		if(l>m-1||m>r)return;
		else{
			rep(i,l,m-1)ins(a[i]);
			int mx=~0u>>1;
			rep(i,m,r)mx=min(mx,ask(a[i]));
			ans+=mx;
			rep(i,l,m-1)del(a[i]);
		}
	}
}
int main(){
	n=rd();
	rep(i,1,n)a[i]=rd();
	sort(a+1,a+n+1);
	solve(MX,1,n);
	cout<<ans<<endl;
}