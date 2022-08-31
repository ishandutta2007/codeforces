#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int f[6][6][202][202],aa[12],bb[12],m;
int main(){
	memset(f,-1,sizeof(f));
	f[0][0][0][0]=0;
	for(re int s1=0; s1<3; ++s1)
		for(re int s2=0; s2<3; ++s2)
			for(re int j=0; j<201; ++j)
				for(re int k=0; k<201; ++k)
					if(~f[s1][s2][j][k]) {
						re int bas=(s1+s2==4?15:25);
						for(re int t2=0; t2+k<201; ++t2) {
							re int t1=max(bas,t2+2);
							if(t1+j>=201)break;
							f[s1+1][s2][j+t1][k+t2]=t1*201+t2;
						}
						for(re int t1=0; t1+j<201; ++t1) {
							re int t2=max(bas,t1+2);
							if(t2+k>=201)break;
							f[s1][s2+1][j+t1][k+t2]=t1*201+t2;
						}
					}
	m=read();
	while(m--) {
		re int a=read(),b=read(),w1=-10,w2=-5,tp=a+b,cnt=a+b;
		for(re int s1=0; s1<=3; ++s1)
			for(re int s2=0; s2<=3; ++s2) {
				if((!(~f[s1][s2][a][b]))||max(s1,s2)<3)continue;
				if(s1-s2>w1-w2)w1=s1,w2=s2;
			}
		if(w1<0) {
			puts("Impossible");
			continue;
		}
		tp=cnt=w1+w2;
		printf("%d:%d\n",w1,w2);
		while(cnt) {
			int t1=f[w1][w2][a][b]/201,t2=f[w1][w2][a][b]%201;
			aa[cnt]=t1,bb[cnt]=t2,a-=t1,b-=t2,cnt--;
			if(t1>t2)w1--;
			else w2--;
		}
		for(int i=1; i<=tp; i++)printf("%d:%d%c",aa[i],bb[i],i<tp?' ':'\n');
	}
}