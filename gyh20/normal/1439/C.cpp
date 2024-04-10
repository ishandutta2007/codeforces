#include<cstdio>
#define re register
using namespace std;
const int Mxdt=1000000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline char pc(char ch,bool bj){
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
void print(int x){
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
void print(long long x){
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline void printnum(int x,char ch){
	print(x),pc(ch,false);
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int n,a[1000002],m;
struct node{
	int mx,se,cnt;
	long long sum;
}tr[4000002];
inline int max(re int x,re int y){return x>y?x:y;}
inline int min(re int x,re int y){return x<y?x:y;}
inline void pu(re int p){
	if(tr[p<<1].mx>tr[p<<1|1].mx)tr[p].mx=tr[p<<1].mx,tr[p].cnt=tr[p<<1].cnt,tr[p].se=max(tr[p<<1].se,tr[p<<1|1].mx);
	else if(tr[p<<1].mx<tr[p<<1|1].mx)tr[p].mx=tr[p<<1|1].mx,tr[p].cnt=tr[p<<1|1].cnt,tr[p].se=max(tr[p<<1|1].se,tr[p<<1].mx);
	else tr[p].mx=tr[p<<1].mx,tr[p].se=max(tr[p<<1].se,tr[p<<1|1].se),tr[p].cnt=tr[p<<1].cnt+tr[p<<1|1].cnt;
	tr[p].sum=tr[p<<1].sum+tr[p<<1|1].sum;
}
inline void build(re int p,re int l,re int r){
	if(l==r){
		tr[p]=(node){a[l],-2000000000,1,a[l]};
		return;
	}
	re int mid=l+r>>1;
	build(p<<1,l,mid),build(p<<1|1,mid+1,r);
	pu(p);
}
inline void lazy(re int p,re int x){
	if(x>=tr[p].mx)return;
	tr[p].sum-=1ll*(tr[p].mx-x)*tr[p].cnt;
	tr[p].mx=x;
}
inline void pd(re int p){lazy(p<<1,tr[p].mx),lazy(p<<1|1,tr[p].mx);}
inline long long asks(re int p,re int l,re int r,re int x,re int y){
	if(l>=x&&r<=y)return tr[p].sum;
	pd(p);re int mid=l+r>>1;re long long ans=0;
	if(x<=mid)ans+=asks(p<<1,l,mid,x,y);
	if(y>mid)ans+=asks(p<<1|1,mid+1,r,x,y);
	return ans;
}
inline void cgm(re int p,re int l,re int r,re int x,re int y,re int w){
	if(w>=tr[p].mx)return;
	if(l>=x&&r<=y&&w>tr[p].se){
		lazy(p,w);
		return;
	}
	pd(p);re int mid=l+r>>1;
	if(x<=mid)cgm(p<<1,l,mid,x,y,w);
	if(y>mid)cgm(p<<1|1,mid+1,r,x,y,w);
	pu(p);
}
inline int askm(re int p,re int l,re int r,re int x,re int y){
	if(l>=x&&r<=y)return tr[p].mx;
	pd(p);re int mid=l+r>>1,ans=0;
	if(x<=mid)ans=max(ans,askm(p<<1,l,mid,x,y));
	if(y>mid)ans=max(ans,askm(p<<1|1,mid+1,r,x,y));
	return ans;
}
inline int find(re int p,re int l,re int r,re int x,re int y,re int z){
	if(l==r){
		if(tr[p].mx>=z)return l;
		return 0;
	}
	pd(p);
	re int mid=l+r>>1;
	if(x<=mid&&tr[p<<1].mx>=z)return find(p<<1,l,mid,x,y,z);
	else return find(p<<1|1,mid+1,r,x,y,z);
}
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)a[i]=-read();
	build(1,1,n);
	while(m--){
		re int opt=read();
		if(opt==1){
			re int x=read(),y=read();
			cgm(1,1,n,1,x,-y);
		}
		else{
			re int x=read(),y=-read(),sum=0;
			while(1){
				re int l=x,r=n,ans=l-1,ia=0;
				for(re int j=x;j<=min(6+x,n);++j){
					if(asks(1,1,n,x,j)<y){
						ans=j-1;
						ia=1;
						break;
					}
				}
				if(!ia){
					l+=6,l=min(l,n);
				while(l<=r){
					re int mid=l+r>>1;
					if(asks(1,1,n,x,mid)>=y)ans=mid,l=mid+1;
					else r=mid-1;
				}
				}
				sum+=ans-x+1;
				if(ans!=x-1)y-=asks(1,1,n,x,ans);
				re int xx=ans;
				if(ans==n)break;
				ans=find(1,1,n,ans+1,n,y);
				if(ans==0)break;
				else x=ans;
			}
			printnum(sum,'\n');
		}
	}
	return pc('o',1);
}