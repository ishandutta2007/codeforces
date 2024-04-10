//2018.11.27 by ljz
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
#define pi acos(-1.0)
#define db double
const int N=4*200000+10;
const char opt[]={'A','G','C','T'};
namespace MAIN{
	int pos[N],lim=1;
	struct cp{
		db x,y;
		cp() {}
		cp(db x,db y):x(x),y(y) {}
	}a[N],b[N],f[N];
	inline cp operator + (const cp &a,const cp &b){
		return cp(a.x+b.x,a.y+b.y);
	}
	inline cp operator - (const cp &a,const cp &b){
		return cp(a.x-b.x,a.y-b.y);
	}
	inline cp operator * (const cp &a,const cp &b){
		return cp(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
	}
	inline void FFT(cp *A,const res &type){
        for(res i=0;i<lim;i++)if(i<pos[i])swap(A[i],A[pos[i]]);
        for(res mid=1;mid<lim;mid<<=1){
            cp wn=cp(cos(pi/mid),type*sin(pi/mid));
            for(res j=0;j<lim;j+=mid<<1){
                cp w=cp(1,0);
                for(res k=0;k<mid;k++,w=w*wn){
                    cp x=A[j+k],y=w*A[j+mid+k];
                    A[j+k]=x+y,A[j+mid+k]=x-y;
                }
            }
        }
        if(type==-1)
            for(res i=0;i<lim;i++)A[i].x=A[i].x/lim+0.5;
    }
	char S[N],T[N];
	int n,m;
	int k;
	int sum[N][4],ans;
	inline void MAIN(){
		n=read(),m=read(),k=read();
		scanf("%s%s",S,T);
		res qaq=0;
    	while(lim<=n+m-2)lim<<=1,qaq++;
    	for(res i=0;i<lim;i++)pos[i]=(pos[i>>1]>>1)|((i&1)<<(qaq-1));
    	for(res i=0;i<n;i++)
    		for(res l=0;l<4;l++)if(S[i]==opt[l])sum[i+1][l]++;
    	for(res i=0;i<n;i++)
			for(res l=0;l<4;l++)sum[i+1][l]+=sum[i][l];	
		for(res l=0;l<4;l++){
			for(res i=0;i<lim;i++){
				if(sum[_min(n,i+k+1)][l]-sum[_max(0,i-k)][l])a[i]=cp(1,0);
				else a[i]=cp(0,0);
			}
			for(res i=0;i<lim;i++){
				if(T[m-i-1]==opt[l])b[i]=cp(1,0);
				else b[i]=cp(0,0);
			}
			FFT(a,1),FFT(b,1);
			for(res i=0;i<lim;i++)f[i]=f[i]+a[i]*b[i];
		}
		FFT(f,-1);
		for(res i=m-1;i<n;i++)if((int)f[i].x==m)ans++;
		printf("%d\n",ans);	
	}
}
int main(){
    MAIN::MAIN();
    return 0;
}