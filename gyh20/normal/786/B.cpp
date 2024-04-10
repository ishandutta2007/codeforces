#include<cstdio>
#include<queue>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
#define ll long long
struct edge{
	int to,next,w;
}e[3200002];
int cnt,head[1600002],n,s,tot,ls[1600002],rs[1600002],ls1[1600002],rs1[1600002],rt1,rt2;
inline void add(re int x,re int y,re int w){
	e[++cnt].to=y;
	e[cnt].w=w;
	e[cnt].next=head[x];
	head[x]=cnt;
}
struct node{
    int pos;
    ll dis;
    bool operator <(const node x)const{
        return dis>x.dis;
    }
}h[1600002];
priority_queue <node> q;
bool v[1600002];
inline ll M(re ll x,re ll y){
    return (x<y)?(x):(y);
}
inline void dis(re int s){for(re int i=1;i<=tot;++i)h[i].dis=1e18,h[i].pos=i;
    h[s].dis=0;
    q.push(h[s]);
    while(!q.empty()){
        while((h[q.top().pos].dis<q.top().dis)){q.pop();if(q.empty())break;
        }
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
}
inline void build1(re int &p,re int l,re int r){
	if(l==r){p=l;return;}
	p=++tot;re int mid=l+r>>1;
	build1(ls[p],l,mid),build1(rs[p],mid+1,r);
	add(p,ls[p],0);add(p,rs[p],0);
}
inline void build2(re int &p,re int l,re int r){
	if(l==r){p=l;return;}
	p=++tot;re int mid=l+r>>1;
	build2(ls[p],l,mid),build2(rs[p],mid+1,r);
	add(ls[p],p,0);add(rs[p],p,0);
}
inline void change(re int p,re int l,re int r,re int x,re int y,re int z,re int w,re int opt){
	if(l>=x&&r<=y){
		opt==2?add(z,p,w):add(p,z,w);
		return;
	}
	re int mid=l+r>>1;
	if(x<=mid)change(ls[p],l,mid,x,y,z,w,opt);
	if(y>mid)change(rs[p],mid+1,r,x,y,z,w,opt);
}
int main(){
	tot=n=read();re int q=read();s=read();
	build1(rt1,1,n);build2(rt2,1,n);
	while(q--){
		re int opt=read(),v,l,r,w;
		if(opt==1){
			l=read();r=read();w=read();
			add(l,r,w);
		}
		else{
			v=read();l=read();r=read();w=read();
			change(opt==2?rt1:rt2,1,n,l,r,v,w,opt);
		}
	}
	dis(s);
	for(re int i=1;i<=n;++i)printf("%lld ",h[i].dis<1e18?h[i].dis:-1);
}