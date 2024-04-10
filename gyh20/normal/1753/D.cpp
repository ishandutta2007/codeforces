#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int&x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}return s;
}
int n,m,X,Y,tot,head[300002],cnt;
vector<char>S[300002];
vector<int>Pos[300002];
char s[300002];
struct edge{
	int to,next,w;
}e[10000002];
inline void add(re int x,re int y,re int z){if(x==0)return;e[++cnt]=(edge){y,head[x],z},head[x]=cnt;}
struct node{
    int pos;ll  dis;
    bool operator <(const node x)const{
        return dis>x.dis;
    }
}h[300002];
priority_queue <node> q;
signed main(){
	n=read(),m=read(),X=read(),Y=read();
	for(re int i=0;i<=n+1;++i)S[i].resize(m+2),Pos[i].resize(m+2);
	for(re int i=1;i<=n;++i){
		scanf("%s",s+1);
		for(re int j=1;j<=m;++j)S[i][j]=s[j],Pos[i][j]=++tot;
	}
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=m;++j)
			if(S[i][j]=='L'){
				if(S[i][j-1]!='#')add(Pos[i][j-1],Pos[i][j+1],Y);
				if(S[i-1][j]!='#')add(Pos[i-1][j],Pos[i][j+1],X);
				if(S[i+1][j]!='#')add(Pos[i+1][j],Pos[i][j+1],X);
			}
			else if(S[i][j]=='R'){
				if(S[i][j+1]!='#')add(Pos[i][j+1],Pos[i][j-1],Y);
				if(S[i-1][j]!='#')add(Pos[i-1][j],Pos[i][j-1],X);
				if(S[i+1][j]!='#')add(Pos[i+1][j],Pos[i][j-1],X);
			}
			else if(S[i][j]=='U'){
				if(S[i-1][j]!='#')add(Pos[i-1][j],Pos[i+1][j],Y);
				if(S[i][j-1]!='#')add(Pos[i][j-1],Pos[i+1][j],X);
				if(S[i][j+1]!='#')add(Pos[i][j+1],Pos[i+1][j],X);
			}
			else if(S[i][j]=='D'){
				if(S[i+1][j]!='#')add(Pos[i+1][j],Pos[i-1][j],Y);
				if(S[i][j-1]!='#')add(Pos[i][j-1],Pos[i-1][j],X);
				if(S[i][j+1]!='#')add(Pos[i][j+1],Pos[i-1][j],X);
			}
	for(re int i=1;i<=tot;++i)h[i].dis=1e18,h[i].pos=i;
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=m;++j)
			if(S[i][j]=='.')
				h[Pos[i][j]].dis=0,q.push(h[Pos[i][j]]);
    while(!q.empty()){
        while((h[q.top().pos].dis<q.top().dis)){q.pop();if(q.empty())break;}
        if(q.empty())break;
        node tmp=q.top();
        q.pop();
        for(re int i=head[tmp.pos];i;i=e[i].next){
            if((tmp.dis+e[i].w)<h[e[i].to].dis){
                h[e[i].to].dis=tmp.dis+e[i].w;
                q.push(h[e[i].to]);
            }
        }
    }
    long long ans=2e18;
    for(re int i=1;i<=n;++i)
    	for(re int j=1;j<=m;++j){
    		if(j<m)ans=min(ans,h[Pos[i][j]].dis+h[Pos[i][j+1]].dis);
    		if(i<n)ans=min(ans,h[Pos[i][j]].dis+h[Pos[i+1][j]].dis);
		}
	if(ans<1e18)printf("%lld",ans);
	else puts("-1");
}