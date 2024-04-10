#include<bits/stdc++.h>
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return !b?a:gcd(b,a%b);}
const int N=6005;
typedef long long ll;
ll ans;
inline ll C(int n,int m){
	if(m==0)return 1;
	if(m==1)return n;
	if(m==2)return 1LL*n*(n-1)/2;
	if(m==3)return 1LL*n*(n-1)*(n-2)/6;
	assert(0);
}
int cnt[12][12],X[3],Y[3],pos;
inline int cross(int x1,int y1,int x2,int y2){
	return x1*y2-x2*y1;
}
void dfs(int x,int y,int cur,ll coef){
	if(!coef)return;
	if(x==12){
		if(cur!=3)return;
		int s=cross(X[2]-X[0],Y[2]-Y[0],X[1]-X[0],Y[1]-Y[0]);
		if(s%2)return;
		s/=2;int tar=s&1;
		int cur=0;
		for(int i=0;i<3;++i){
			for(int j=i+1;j<3;++j){
				cur+=gcd(abs(X[i]-X[j]),abs(Y[i]-Y[j]))%4;
			}
		}
		cur%=4;
		if(cur%2==0&&cur/2==tar)ans+=coef;
		return;
	}
	if(y==12)return dfs(x+1,0,cur,coef);
	int o=pos;
	for(int i=0;i+cur<=3&&i<=cnt[x][y];++i){
		if(i)X[pos]=x,Y[pos]=y,++pos;
		dfs(x,y+1,i+cur,coef*C(cnt[x][y],i));
	}
	pos=o;
}
int main(){
	int n;read(n);
	for(int i=1;i<=n;++i){
		int x,y;read(x,y);
		++cnt[x%12][y%12];
	}
	dfs(0,0,0,1);
	printf("%lld\n",ans);
	return 0;
}