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
struct node{
	int pos,x,y;
}p1[1000002],p2[1000002];
int n,m,t,a[1000002],n1,n2,ans,lp1,lp2;
signed main(){
	t=read();
	while(t--){
		n=read(),m=read();n1=n2=0;
		for(re int i=1;i<=n;++i)a[i]=read();
		int sum=0,mn=0;
		for(re int i=m-1;i;--i){
			sum+=a[i],mn=min(mn,sum);
			if(sum>=0)p1[++n1]=(node){i,mn,sum},mn=sum=0;
		}sum=mn=0;
		for(re int i=m+1;i<=n;++i){
			sum+=a[i],mn=min(mn,sum);
			if(sum>=0)p2[++n2]=(node){i,mn,sum},mn=sum=0;
		}
		re int pp1=1,pp2=1;
		ans=a[m],lp1=lp2=m;
		while(1){
			if(pp1<=n1&&ans+p1[pp1].x>=0)ans+=p1[pp1].y,lp1=p1[pp1].pos,++pp1;
			else if(pp2<=n2&&ans+p2[pp2].x>=0)ans+=p2[pp2].y,lp2=p2[pp2].pos,++pp2; 
			else break;
		}
		int cur=ans,ia=1;
		for(re int i=lp1-1;i&&ia;--i)cur+=a[i],ia&=cur>=0;
		if(ia){
			puts("YES");
			continue;
		}
		cur=ans,ia=1;
		for(re int i=lp2+1;i<=n&&ia;++i)cur+=a[i],ia&=cur>=0;
		if(ia){
			puts("YES");
			continue;
		}puts("NO");
	}
}