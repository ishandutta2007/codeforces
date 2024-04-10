#include<bits/stdc++.h>
#define re register
using namespace std;
char rbuf[40000002],wbuf[80000002];
int pt=-1,pt1=-1;
inline int read(){
	re int t=0;re char v=rbuf[++pt];
	while(v<'0')v=rbuf[++pt];
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=rbuf[++pt];
	return t;
}
int n,m,f[1000002][2],n1,n2,T,a[1000002],b[1000002],A[2000002],cc,fr[1000002][2],curx,cury,ss;
char g[1000002][2],usd[1000002],typ[1000002];
vector<int>ans,X,Y;
inline int gmx(re int &x,re int y){
	if(y>x){x=y;return 1;}
	return 0;
}
inline void Out(re int x,re int y){
	usd[x]=y;
	if(x==0){
		if(y)ans.push_back(0);
		return;
	}
	if(fr[x][y]==2){
		ans.push_back(A[x]);
		Out(x,y^1),typ[x]=2;
		return;
	}
	if(fr[x][y]==1){
		ans.push_back(A[x-1]+1);
		Out(x-1,y^1);
		return;
	}
	Out(x-1,y);
}
inline void write(re int x){
	if(x>9)write(x/10);
	wbuf[++pt1]=x%10+'0';
}
int main(){
	fread(rbuf,1,40000000,stdin),n=read(),n1=read(),n2=read(),T=read();
	for(re int i=1;i<=n1;++i)a[i]=read(),A[++cc]=a[i];
	for(re int i=1;i<=n2;++i)b[i]=read(),A[++cc]=b[i];
	A[++cc]=n+1;
	sort(A+1,A+cc+1),cc=unique(A+1,A+cc+1)-A-1;
	re int pos=1;
	for(re int i=1;i<=n1;++i){
		while(A[pos]<a[i])++pos;
		g[pos][0]=1;
	}
	pos=1;
	for(re int i=1;i<=n2;++i){
		while(A[pos]<b[i])++pos;
		g[pos][1]=1;
	}
	for(re int i=1;i<=cc;++i){
		for(re int o=0;o<2;++o){
			f[i][o]=f[i-1][o]+A[i]-A[i-1],fr[i][o]=0;
			if(g[i][o]){
				if(f[i][o]>T)f[i][o]-=T;
				else f[i][o]=-1.1e9;
			}
			if(A[i]!=A[i-1]+1){
				re int tmp=min(T,f[i-1][o^1]+1);
				if(!g[i][o]){
					if(gmx(f[i][o],tmp+A[i]-A[i-1]-1))fr[i][o]=1;
				}
				else if(tmp+A[i]-A[i-1]-1-1>=T){
					if(gmx(f[i][o],tmp+A[i]-A[i-1]-1-T))fr[i][o]=1;
				}
			}
		}
		if(!g[i][0]){
			if(gmx(f[i][0],min(f[i][1],T)))fr[i][0]=2;
		}
		if(!g[i][1]){
			if(gmx(f[i][1],min(f[i][0],T)))fr[i][1]=2;
		}
	}
	if(max(f[cc][0],f[cc][1])>=0)puts("Yes");
	else{
		puts("No");
		return 0;
	}
	re int o=f[cc][1]>f[cc][0];
	Out(cc,o);
	sort(ans.begin(),ans.end());
	write(ans.size()),wbuf[++pt1]='\n';
	for(re int i=0;i<ans.size();++i)write(ans[i]),wbuf[++pt1]=' ';
	wbuf[++pt1]='\n';
	curx=cury=0;ss=T;
	if(usd[0]==1)cury=1;
	for(re int i=1;i<=cc;++i){
		if(usd[i]==cury){
			if(g[i][usd[i]])X.push_back(ss),Y.push_back(cury),ss+=T;
		}
		else{
			ss=max(ss,A[i-1]+1),cury^=1;
			if(g[i][usd[i]])X.push_back(ss),Y.push_back(cury),ss+=T;
		}
		if(typ[i]==2)ss=max(ss,A[i]),cury^=1;
	}
	write(X.size()),wbuf[++pt1]='\n';
	for(re int i=0;i<X.size();++i)write(X[i]),wbuf[++pt1]=' ',write(Y[i]+1),wbuf[++pt1]='\n';
	fwrite(wbuf,1,pt1+1,stdout);
}