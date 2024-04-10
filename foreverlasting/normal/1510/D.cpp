#include<bits/stdc++.h>
using namespace std;
int n;
const int N=1e5+10;
#define res register int
#define gc getchar
inline int read(){
	res s=0,w=1,ch=gc();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=gc();
	}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
	return s*w;
}
inline void swap(res &x,res &y){
	x^=y^=x^=y;
}
#define db long double
#define Pair pair<db,int>
Pair f[N][10];
db a[N];
int b[N];
#define fi first
#define se second
#define mp make_pair
int main(){
	n=read();
	res d=read();
	for(res i=1;i<=n;i++){
		res x=read();
		b[i]=x;
		a[i]=log(x);
	}
	for(res i=0;i<=9;i++)f[0][i]=mp(-1.0,0);
	f[0][1]=mp(0,0);
	for(res i=1;i<=n;i++){
		for(res j=0;j<=9;j++)f[i][j]=f[i-1][j];
		for(res j=0;j<=9;j++){
			if(f[i-1][j].fi>=0-1e-8)
			{
				if(f[i-1][j].fi+a[i]>f[i][j*b[i]%10].fi){
					f[i][j*b[i]%10]=mp(f[i-1][j].fi+a[i],f[i-1][j].se+1);
				}
			}
		}
	}
//	for(res i=0;i<=n;i++){
//		for(res j=0;j<=9;j++){
//			printf("%d %d %.3Lf %d\n",i,j,f[i][j].fi,f[i][j].se);
//		}
//		puts("");
//	}
	if(f[n][d].se==0){puts("-1");return 0;}
	printf("%d\n",f[n][d].se);
	res cur=d;
	for(res i=n;i;i--){
		if(f[i][cur]==f[i-1][cur])continue;
//		printf("%d %d\n",i,cur);
		for(res j=0;j<=9;j++){
			if(f[i-1][j].fi+a[i]==f[i][cur].fi&&f[i-1][j].se+1==f[i][cur].se&&(((j*b[i])%10)==cur)){
				cur=j;break;
			}
		}
		printf("%d ",b[i]);
	}
	puts("");
	return 0;
}