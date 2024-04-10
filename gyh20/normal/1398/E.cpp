#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
int t,n,m,a[200002],ans,pos[200002],val[200002],opt[200002],typ[200002],lsh[200002],sum,cc[2][200002],num,vvv[200002];
inline void add(re int*c,re int x,re int y){//printf("add:%lld %lld\n",x,y);
for(;x<=n;x+=x&(-x))c[x]+=y;}
inline int ask(re int*c,re int x){
	re int anss=0;
	for(;x;x-=x&(-x))anss+=c[x];
	return anss;
}
priority_queue<int>q,d;
inline int first(){
	while(!q.empty()&&!d.empty()&&q.top()==d.top())q.pop(),d.pop();
	return q.empty()?0:-q.top();
}
map<int,int>vv;
signed main(){
	n=read();
	for(re int i=1;i<=n;++i){
		typ[i]=read();
		val[i]=read();
		if(val[i]>0)opt[i]=1;
		else opt[i]=2,val[i]=-val[i];
		lsh[i]=val[i];
	}
	sort(lsh+1,lsh+n+1);
	for(re int i=1;i<=n;++i)pos[i]=lower_bound(lsh+1,lsh+n+1,val[i])-lsh,pos[i]=n-pos[i]+1,vv[val[i]]=pos[i],vvv[pos[i]]=val[i];
	for(re int i=1;i<=n;++i){
	//	printf("%lld %lld\n",pos[i],val[i]);
		if(opt[i]==1){
			if(typ[i]==0)sum+=val[i],add(cc[0],pos[i],val[i]),add(cc[1],pos[i],1);
			else sum+=val[i],add(cc[0],pos[i],val[i]),q.push(-val[i]),++num,add(cc[1],pos[i],1);
		}
		else{
			if(typ[i]==0)sum-=val[i],add(cc[0],pos[i],-val[i]),add(cc[1],pos[i],-1);
			else sum-=val[i],add(cc[0],pos[i],-val[i]),d.push(-val[i]),--num,add(cc[1],pos[i],-1);
		}
		int qq=first();//printf("%lld %lld\n",i,qq);
		if(qq){
			re int l=1,r=n,anss=0,poss=vv[qq];
			add(cc[0],poss,-qq);add(cc[1],poss,-1);
			while(l<=r){
				re int mid=l+r>>1;
				if(ask(cc[1],mid)<=num)l=mid+1,anss=mid;
				else r=mid-1;
			}
			re int aaa=sum+ask(cc[0],anss),lfo=num-ask(cc[1],anss);
			if(lfo&&anss<n)aaa+=vvv[anss+1]*lfo; 
			printf("%lld\n",aaa);
			add(cc[0],poss,qq);add(cc[1],poss,1);
		}
		else printf("%lld\n",sum);
	}
}