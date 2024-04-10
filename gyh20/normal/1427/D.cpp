#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
int n,m,t,a[100002],b[100002],dp[100002],tp,mx,pos;
vector<int>v[100002];
char s[200002];
inline void work2(re int x,re int y){
	v[pos].push_back(x),v[pos].push_back(y);
	re int c=x+1;
	for(re int i=1;i<=y;++i)b[i]=a[c++];
	c=1;
	for(re int i=y+1;i<=n;++i)b[i]=a[c++];
}
inline void work3(re int x,re int y,re int z){
	v[pos].push_back(x),v[pos].push_back(y),v[pos].push_back(z);
	re int c=x+y+1;
	for(re int i=1;i<=z;++i)b[i]=a[c++];
	c=x+1;
	for(re int i=z+1;i<=z+y;++i)b[i]=a[c++];
	c=1;
	for(re int i=z+y+1;i<=n;++i)b[i]=a[c++];
}
inline void work4(re int x,re int y,re int z,re int u){
	v[pos].push_back(x),v[pos].push_back(y),v[pos].push_back(z),v[pos].push_back(u); 
	re int c=x+y+z+1;
	for(re int i=1;i<=u;++i)b[i]=a[c++];
	c=x+y+1;
	for(re int i=u+1;i<=u+z;++i)b[i]=a[c++]; 
	c=x+1;
	for(re int i=u+z+1;i<=u+z+y;++i)b[i]=a[c++];
	c=1;
	for(re int i=u+z+y+1;i<=n;++i)b[i]=a[c++];
}
int pp[102],rr[102],lst[102];
int main(){
	n=m=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=2;i<=n;++i){
		re int pos1=0,pos2=0,val;pos=i-1;
		for(re int j=1;j<=n;++j)pp[a[j]]=j;
		for(re int j=2;j<=n;++j)if(pp[j]<pp[j-1])pos1=pp[j-1],pos2=pp[j],val=j;
		if(!pos1){
			n=i-1;break;
		}
		if(pos2==1&&pos1==n)work2(1+rr[val],n-1-rr[val]);
		else if(pos2==1)work3(1+rr[val],pos1-1-rr[val],n-pos1);
		else if(pos1==n)work3(pos2-1,1+rr[val],n-pos2-rr[val]);
		else work4(pos2-1,1+rr[val],pos1-pos2-rr[val],n-pos1);
		for(re int j=1;j<=n;++j)a[j]=b[j];
		lst[val-1]=val;
		for(re int k=1;k<=n;++k)for(re int j=1;j<=n;++j)if(lst[j])rr[j]=rr[lst[j]]+1;
	}
	printf("%d\n",n-1);
	for(re int i=1;i<n;++i){
		printf("%d ",v[i].size());
		for(re int j=0;j<v[i].size();++j)printf("%d ",v[i][j]);
		puts("");
	}
}