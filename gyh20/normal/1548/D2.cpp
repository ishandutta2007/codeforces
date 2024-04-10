#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,X[6002],Y[6002],b[4][4][4];
ll ans1,ans2;
int main(){
	n=read();
	for(re int i=1;i<=n;++i)X[i]=read(),Y[i]=read();
	for(re int i=1;i<=n;++i){
		memset(b,0,sizeof(b));
		for(re int j=1;j<=n;++j)if(j^i)++b[X[j]&3][Y[j]&3][__gcd(abs(X[j]-X[i]),abs(Y[j]-Y[i]))&3];
		for(re int a1=0;a1<4;++a1)
			for(re int b1=0;b1<4;++b1)
				for(re int c1=0;c1<4;++c1)if(b[a1][b1][c1]){
					re int oo=b[a1][b1][c1];--b[a1][b1][c1];
					for(re int a2=a1&1;a2<4;a2+=2)
						for(re int b2=b1&1;b2<4;b2+=2)
							for(re int c2=c1&1;c2<4;++c2){
								re ll tmp=1ll*X[i]*(b2-b1)+1ll*a1*(Y[i]-b2)+1ll*a2*(b1-Y[i]);
								tmp%=4,tmp+=4,tmp%=4,tmp>>=1;
								re int c3=__gcd(abs(a1-a2),abs(b1-b2));
								tmp-=(c1+c2+c3)/2;
								if(!(tmp&1)){
									if(c1&1)ans1+=1ll*oo*b[a2][b2][c2];
									else ans2+=1ll*oo*b[a2][b2][c2];
								}
							}
					b[a1][b1][c1]=oo;
				}
	}
	printf("%lld",ans1/2+ans2/6);
}