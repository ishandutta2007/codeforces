#include<bits/stdc++.h>
using namespace std;
#define int long long
#define re register
inline int read() {
	re int t=0;
	re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,t,ans,p[40002],tot,a[40002];
bool ip[40002];
long long ss;
struct node{
	int x,y,z;
	bool operator <(const node a)const{
		return a.y==y?a.x<x:a.y>y;
	}
}b[40002];
priority_queue<node>q;
inline int gcd(re int x,re int y){
	return y?gcd(y,x%y):x;
}
signed main() {
	t=read();
	n=4e4;
	for (int i=2; i<=n; ++i) {
		if (!ip[i])p[++tot]=i;
		for(int j=1; j<=tot&&i*p[j]<=n; ++j) {
			ip[i*p[j]]=1;
			if(i/p[j]*p[j]==i)break;
		}
	}
	while(t--){//re int kkk=read();
		while(!q.empty())q.pop();ans=1;
		for(re int i=1;i<=tot;++i)q.push((node){p[i],1,p[i]});
		for(re int jj=1;jj<=22;++jj){
			re int x=1,cnt=0;
			while(!q.empty()){
				node tmp=q.top();q.pop();
				if(1.0*x*tmp.x>1e18){q.push(tmp);break;}
				b[++cnt]=tmp,x*=tmp.x;
			}
			printf("? %lld\n",x);
			fflush(stdout);
			ss=read();
			for(re int i=1;i<=cnt;++i){
				if(ss%b[i].x==0){
					ans/=b[i].y;
					++b[i].y;
					ans*=b[i].y;
					b[i].x*=b[i].z;
					q.push(b[i]);
				}
			}
		}
		printf("! %lld\n",ans*2);
		fflush(stdout);
	}
}