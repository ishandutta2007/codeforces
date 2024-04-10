//2019.2.24 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
inline int read(){
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void _swap(res &x,res &y){
    x^=y^=x^=y;
}
inline int _abs(const res &x){
    return x>0?x:-x;
}
inline int _max(const res &x,const res &y){
    return x>y?x:y;
}
inline int _min(const res &x,const res &y){
    return x<y?x:y;
}
const int N=1e6+10;
const int M=1e5+10;
namespace MAIN{
	int n,m,dx,dy;
	int a[N],sum[N],mx,ans;
	inline void MAIN(){
		n=read(),m=read(),dx=read(),dy=read();
		for(res j=0,x=0,y=0;j<n;j++)a[x]=y,x=(x+dx)%n,y=(y+dy)%n;
		for(res i=1;i<=m;i++){
			res x=read(),y=read(),k=(y-a[x]+n)%n;
			sum[k]++;
			if(sum[k]>mx)mx=sum[k],ans=k;
		}
		printf("0 %d\n",ans);
	}
}
int main(){
    MAIN::MAIN();
    return 0;
}