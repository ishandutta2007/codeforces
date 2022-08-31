#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
char s[300002],t[300002];
int n,m,M1,M2,p[102],mn,H1[300002],H2[300002],*h1=H1+1,*h2=H2+1,pw1[300002],pw2[300002];
const int B1=1145141,B2=19260817;
struct node{
	int x,y;
	bool operator ==(const node A)const{return x==A.x&&y==A.y;}
	node operator +(const node A)const{return (node){(x+A.x)%M1,(y+A.y)%M2};}
	node operator *(const int A)const{return (node){1ll*x*pw1[A]%M1,1ll*y*pw2[A]%M2};}
};
vector<node>V[1048576];
inline void build(re int p,re int l,re int r){
	if(l==r){V[p].push_back((node){s[l],s[l]});return;}
	re int mid=l+r>>1;
	build(p<<1,l,mid),build(p<<1|1,mid+1,r);
	V[p].resize(r-l+1);re int len=V[p].size();
	for(re int j=0;j<len/2;++j){
		V[p][j]=(V[p<<1][j]*(len/2)+V[p<<1|1][j]);
		V[p][j+len/2]=(V[p<<1|1][j]*(len/2)+V[p<<1][j]);
	}
}
inline bool cmp(re int d,re int x,re int y,re int p1,re int l1,re int r1,re int p2,re int l2,re int r2){
	if(d==0)return s[l1]<s[l2];
	re int mid1=l1+r1>>1,mid2=l2+r2>>1;
	re int la1=l1,ra1=mid1,la2=mid1+1,ra2=r1,lb1=l2,rb1=mid2,lb2=mid2+1,rb2=r2;p1<<=1,p2<<=1;
	if(x&(1<<d-1))swap(la1,la2),swap(ra1,ra2),p1^=1,x^=1<<d-1;
	if(y&(1<<d-1))swap(rb1,rb2),swap(lb1,lb2),p2^=1,y^=1<<d-1;
	if(V[p1][x]==V[p2][y])return cmp(d-1,x,y,p1^1,la2,ra2,p2^1,lb2,rb2);
	else return cmp(d-1,x,y,p1,la1,ra1,p2,lb1,rb1);
}
inline bool cmp(re int x,re int y){
	return cmp(n,x,y,1,0,m-1,1,0,m-1);
}
int main(){
	p[1]=1e9+7,p[2]=1e9+9,p[3]=998244353,p[4]=998244853,p[5]=1000000021,p[6]=1000000033,p[7]=1000000087,p[8]=1000000093;
	srand(time(0)),M1=p[rand()%8+1];
	n=read(),m=(1<<n),scanf("%s",s);
	for(re int i=pw1[0]=1;i<=m;++i)pw1[i]=1ll*pw1[i-1]*B1%M1;
	for(re int i=0;i<m;++i)h1[i]=(1ll*h1[i-1]*B1+s[i])%M1;
	M2=p[rand()%8+1];
	for(re int i=pw2[0]=1;i<=m;++i)pw2[i]=1ll*pw2[i-1]*B2%M2;
	for(re int i=0;i<m;++i)h2[i]=(1ll*h2[i-1]*B2+s[i])%M2;
	build(1,0,m-1); 
	for(re int i=1;i<m;++i)if(cmp(i,mn))mn=i;
	for(re int i=0;i<m;++i)t[i]=s[i^mn];
	printf("%s",t);
}