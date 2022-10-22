//2018.10.23 by ljz
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
const int N=1e3+10;
const int kcz=1e9+7;
namespace MAIN{
	int n;
	int a[N][N];
	int f[N][N],g[N][N];
	inline void add(res &x,const res &y){
		x+=y;
		x>=kcz?x-=kcz:1;
	}
	inline void MAIN(){
		n=read();
		for(res i=1;i<=n;i++)
			for(res j=1;j<=n;j++)a[i+n][j]=a[i][j+n]=a[i+n][j+n]=a[i][j]=read();
		for(res i=1;i<=n<<1;i++)f[i][i]=1;
		for(res o=2;o<=n;o++)
			for(res l=1,r=o;r<=n<<1;l++,r++){
				if(o==2)g[l][r]=a[l][r];
				else for(res k=l;k<r;k++)if(a[l][r])add(g[l][r],1LL*f[l][k]*f[k+1][r]%kcz);
				for(res k=l;k<r;k++)add(f[l][r],1LL*f[l][k]*g[k][r]%kcz);
			}
		printf("%d\n",f[1][n]);		
	}
}
int main(){
    MAIN::MAIN();
    return 0;
}