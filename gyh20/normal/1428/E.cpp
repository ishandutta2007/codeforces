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
int n,k,t,a[200002],b[200002],ans,sum[200002],s;
inline int calc(re int x,re int y){
	if(y>=x)return x;
	re int xx=((x-1)/y),num=x-xx*y,num1=y-num;
	return num*(xx+1)*(xx+1)+num1*xx*xx;
}
struct node{
	int val,tim;
	bool operator <(const node &x)const{
		return calc(val,tim)-calc(val,tim+1)<calc(x.val,x.tim)-calc(x.val,x.tim+1);
	}
};
priority_queue<node>q;
signed main(){
	n=read(),k=read();k-=n;
	for(re int i=1;i<=n;++i)a[i]=read(),q.push((node){a[i],1}),ans+=a[i]*a[i];
	for(re int i=1;i<=k;++i){
		node x=q.top();q.pop();
		ans-=calc(x.val,x.tim)-calc(x.val,x.tim+1);
		q.push((node){x.val,x.tim+1});
	}
	printf("%lld",ans);
}