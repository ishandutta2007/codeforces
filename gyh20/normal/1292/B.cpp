#include<cstdio>
#define re register
using namespace std;
long long x0,y0,a1,a2,b1,b2,xs,ys,tt,X1,X2,Y1,Y2,a,b,x[1002],y[1002];
inline long long read(){
	re long long t=0;
	re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0'){
		t=(t<<3)+(t<<1)+v-'0';
		v=getchar();
	}
	return t;
}
inline long long ABS(re long long x){
	return x>0?x:-x;
}
long long cnt=1;
inline long long dis(re long long xx,re long long yy,re long long XX,re long long YY){
	return ABS(xx-XX)+ABS(yy-YY);
}
inline long long ac(re long long p){
	long long t=tt;
	if(dis(xs,ys,x[p],y[p])>t)return 0;
	if(dis(xs,ys,x[p],y[p])==t)return 1;
	t-=dis(xs,ys,x[p],y[p]);
 
	for(re long long i=p-1;i>=1;--i){
		if(dis(x[p],y[p],x[i],y[i])>t){
			return p-i;
		}
	}
	long long ans=cnt,ans1=cnt;
	t-=dis(x[p],y[p],x[1],y[1]);
	for(re long long i=p+1;i<=cnt;++i){
		if(dis(x[1],y[1],x[i],y[i])>t){ans=i-1;break;}
	}
	for(re long long i=p+1;i<=cnt;++i){
		if(dis(x[p],y[p],x[i],y[i])*2>t){
			ans1=i-1;
			break;
		}
	}
	if(ans>ans1)
	return ans;
	else return ans1;
}
inline void write(re long long xx){
	if(xx>9)write(xx/10);
	putchar((xx%10)+48);
}
signed main(){
	x0=read();
	y0=read();
	a1=read();
	a2=read();
	b1=read();
	b2=read();
	xs=read();
	ys=read();
	tt=read();
x[1]=x0;
y[1]=y0;	
 
while(1){
	++cnt;
	x[cnt]=x[cnt-1]*a1+b1;
	y[cnt]=y[cnt-1]*a2+b2;
	if(x[cnt]>=(2e16)||y[cnt]>=(2e16))break;
}
long long ans=0,tmp,mn=9e18,pos;
for(re long long i=1;i<=cnt;++i){
	if(dis(xs,ys,x[i],y[i])<mn){
		mn=dis(xs,ys,x[i],y[i]),pos=i;
	}
}
if(pos!=1){
	tmp=ac(pos-1);
	if(tmp>ans)ans=tmp;
}
tmp=ac(pos);
	if(tmp>ans)ans=tmp;
if(pos!=cnt){
	tmp=ac(pos+1);
	if(tmp>ans)ans=tmp;
}
write(ans);
}