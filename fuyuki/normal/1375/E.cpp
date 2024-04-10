#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0;char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=3e6+1,sgn[2]={1,-1},INF=0x3f3f3f3f;
int T,n,k;
int a[N],b[N],c[N],tmp[N];
I cmp(int x,int y){return b[x]==b[y]?x<y:b[x]<b[y];}
int main(){
	n=getint();
	FOR(i,1,n)a[i]=getint(),b[i]=a[i],c[i]=i;
	FOR(i,1,n)FOR(j,i+1,n)if(a[i]>a[j])k++;
	cout<<k<<'\n',sort(c+1,c+1+n,cmp);
	FOR(i,1,n){
		k=0;
		FOR(j,c[i]+1,n)if(a[c[i]]>a[j])tmp[++k]=j;
		sort(tmp+1,tmp+1+k,cmp);
		ROF(j,k,1)cout<<c[i]<<' '<<tmp[j]<<'\n',swap(b[c[i]],b[tmp[j]]);
	}
	return 0;
}