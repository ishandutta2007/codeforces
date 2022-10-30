#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005,S=150;
int a[N],n,c[N];
void add(int x,int C){for(++x;x<=n;x+=lowbit(x))c[x]+=C;}
int find(int lim){
	int p=0,s=0;
	for(int i=17;i>=0;--i)if(p+(1<<i)<=n&&s+c[p+(1<<i)]<lim)p+=1<<i,s+=c[p];
	return p;
}
int ask(int x){
	++x;int ans=0;for(;x;x-=lowbit(x))ans+=c[x];
	return ans;
}
struct BLOCK{
	int a[S+5],x[S+5],y[S+5],len,pos;
	void rebuild(){
		x[0]=0,pos=1;for(int i=0;i<len;++i)add(x[pos++]=find(a[i]),1);
		std::sort(x,x+pos);for(int i=0;i<pos;++i)y[i]=ask(x[i])-x[i];
		for(int i=1;i<pos;++i)add(x[i],-1);
	}
	inline void trans(int &p){p+=y[std::upper_bound(x,x+pos,p)-x-1];}
}b[N/S+5];
int main(){
	read(n);int mb=(n-1)/S;
	for(int i=0;i<n;++i)read(a[i]);
	for(int i=1;i<=n;++i)add(i,1);
	for(int l=0,r=S-1,cur=0;l<n;l+=S,r+=S){
		r=std::min(r,n-1),b[cur].len=r-l+1;
		for(int i=l;i<=r;++i)b[cur].a[i-l]=a[i];
		b[cur++].rebuild();
	}
	int q,opt,x,y;read(q);
	while(q--){
		read(opt,x),--x;
		if(opt==1)read(y),b[x/S].a[x%S]=y,b[x/S].rebuild(),a[x]=y;
		else{
			int lim=a[x];++x;
			for(int i=x,ed=std::min(n,(x/S+1)*S);i<ed;++i)if(a[i]<=lim)++lim;
			for(int i=x/S+1;i<=mb;++i)b[i].trans(lim);
			printf("%d\n",n-lim);
		}
	}
	return 0;
}