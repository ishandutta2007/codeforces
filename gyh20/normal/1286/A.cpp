#include<bits/stdc++.h>
using namespace std;
#define re register
inline int read(){
	re int t=0,f=1;
	re char v=getchar();
	while(v<'0'||v>'9'){
		if(v=='-')f=-1;
	v=getchar();}
	while(v>='0'&&v<='9'){
		t=(t<<3)+(t<<1)+(v^48);
		v=getchar();
	}
	return t*f;
}
int n,a[1002],ans,f[102][102][102][2],nod,nev;
int main(){
n=read();
nod=(n+1)/2;
nev=n/2;
for(re int i=1;i<=n;++i){a[i]=read();
}
memset(f,127,sizeof(f));
f[0][0][0][0]=f[0][0][0][1]=0;
int k;
for(re int i=1;i<=n;++i){
	if(a[i]){
		if(a[i]&1){
			for(re int j=1;j<=i;++j){
				k=i-j;
					f[i][j][k][1]=min(f[i-1][j-1][k][1],f[i-1][j-1][k][0]+1);
			}
		}
		else{
			for(re int j=0;j<i;++j){
				k=i-j;
					f[i][j][k][0]=min(f[i-1][j][k-1][0],f[i-1][j][k-1][1]+1);
				
			}
		}
	}
	else{
		for(re int j=1;j<=i;++j){
				k=i-j;
					f[i][j][k][1]=min(f[i-1][j-1][k][1],f[i-1][j-1][k][0]+1);
			}
		for(re int j=0;j<i;++j){
				k=i-j;
					f[i][j][k][0]=min(f[i-1][j][k-1][0],f[i-1][j][k-1][1]+1);
				
			}
		
	}
 
}
printf("%d",min(f[n][nod][nev][0],f[n][nod][nev][1]));
}