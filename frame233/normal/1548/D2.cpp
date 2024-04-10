#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return !b?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
const int N=6005;
int x[N],y[N],cnt[4][4][4];
inline int cross(int x1,int y1,int x2,int y2){return x1*y2-x2*y1;}
int main(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(x[i],y[i]);
	long long A=0,B=0;
	for(int i=1;i<=n;++i){
		memset(cnt,0,sizeof(cnt));for(int j=1;j<=n;++j)if(i!=j)++cnt[x[j]%4][y[j]%4][gcd(abs(x[i]-x[j]),abs(y[i]-y[j]))%4];
		int X=x[i]%4,Y=y[i]%4;
		for(int x1=0;x1<4;++x1)for(int y1=0;y1<4;++y1)for(int x2=x1%2;x2<4;x2+=2)for(int y2=y1%2;y2<4;y2+=2){
			int s=(cross(x1-X,y1-Y,x2-X,y2-Y)%4+4)%4;
			if(s%2)continue;
			int g=gcd((x1-x2+4),(y1-y2+4));
			for(int a=0;a<4;++a)for(int b=0;b<4;++b){
				if((a+b+g)%4==s){
					int coef=x1==x2&&y1==y2&&a==b?cnt[x1][y1][a]*(cnt[x2][y2][b]-1):cnt[x1][y1][a]*cnt[x2][y2][b];
					(a%2==0?A:B)+=coef;
				}
			}
		}
	}
	printf("%lld\n",A/6+B/2);
	return 0;
}