#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353,inf=1e9;
int n,m,M,A,B,t,a[2000005],f[2000005][2],fr[2000005][2],mncnt[2000005][2],s[2000005],c[2000005],d[2000005],cnt[2000005],S[2000005];
pr b[2000005];
void upd(int x,int y,int z,int w){
	if(w>f[x][y])f[x][y]=w,fr[x][y]=z,mncnt[x][y]=mncnt[x-1][z]+(y!=z);
	else if(w==f[x][y]&&mncnt[x-1][z]+(y!=z)<mncnt[x][y])fr[x][y]=z,mncnt[x][y]=mncnt[x-1][z]+(y!=z);
}
int p1=2000000,p2=0;
char buf[2000005],wbuf[2000005];
int gc(){
	return getchar();
	if(p1>=2000000)fread(buf,1,2000000,stdin),p1=0;
	return buf[p1++];
}
int rd(){
	int x=0;
	char ch=gc();
	while(ch<'0'||ch>'9')ch=gc();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=gc();
	return x;
}
void pc(char x){
	if(p2==2000000)fwrite(wbuf,1,p2,stdout),p2=0;
	wbuf[p2++]=x;
}
void wrt(int x){
	if(x<0)return pc('-'),wrt(-x);
	if(!x)return pc('0');
	int t[20]={0};
	while(x)t[++t[0]]=x%10,x/=10;
	while(t[0])pc(t[t[0]--]+'0');
}
void Print(int ty){
	int y=ty;
	for(int i=m;i>=2;i--){
		d[i]=y;
		if(fr[i][y]!=y)s[++s[0]]=a[i-1];
		y=fr[i][y];
	}
	d[1]=y;
	reverse(s+1,s+s[0]+1);
	wrt(s[0]),pc('\n');
	for(int i=1;i<=s[0];i++)wrt(s[i]),pc(' ');
	pc('\n');
	s[0]=0;
	for(int i=2,lst=1,lstv=0;i<=m;i++){
		if(d[i]!=d[i-1])lst=i-1,lstv=min(t,f[i-1][d[i-1]]);
		if(c[i]&(1<<d[i])){
			cnt[lst]++;
			s[++s[0]]=a[lst]+cnt[lst]*t-lstv;
			S[s[0]]=d[i];
		}
	}
	wrt(s[0]),pc('\n');
	for(int i=1;i<=s[0];i++)wrt(s[i]),pc(' '),wrt(S[i]+1),pc('\n');
}
int main(){
	n=rd(),A=rd(),B=rd(),t=rd(),b[++M]=pr(0,0),b[++M]=pr(n+1,0);
	for(int i=1,x;i<=A;i++){
		x=rd(),b[++M]=pr(x,1),b[++M]=pr(x+1,0);
	}
	for(int i=1,x;i<=B;i++){
		x=rd(),b[++M]=pr(x,2),b[++M]=pr(x+1,0);
	}
	sort(b+1,b+M+1);
	for(int i=1,j;i<=M;i=j+1){
		j=i,a[++m]=b[i].first,c[m]=b[i].second;
		while(j<M&&b[j+1].first==b[i].first)j++,c[m]|=b[j].second;
	}
	for(int i=1;i<=m;i++)f[i][0]=f[i][1]=-inf;
	f[1][0]=0;
	for(int i=2;i<=m;i++){
		int x=c[i],lx=c[i-1];
		if(f[i-1][0]>=0){
			if(x&1){
				if(f[i-1][0]+(a[i]-1-a[i-1])>=t)upd(i,0,0,f[i-1][0]+(a[i]-a[i-1])-t);
			}
			else {
				upd(i,0,0,f[i-1][0]+(a[i]-a[i-1]));
			}
			if(x&2){
				if(lx&2);
				else if(min(t,f[i-1][0])+(a[i]-1-a[i-1])>=t)upd(i,1,0,min(t,f[i-1][0])+(a[i]-a[i-1])-t);
			}
			else {
				if(lx&2);
				else upd(i,1,0,min(t,f[i-1][0])+(a[i]-a[i-1]));
			}
		}
		if(f[i-1][1]>=0){
			if(x&2){
				if(f[i-1][1]+(a[i]-1-a[i-1])>=t)upd(i,1,1,f[i-1][1]+(a[i]-a[i-1])-t);
			}
			else {
				upd(i,1,1,f[i-1][1]+(a[i]-a[i-1]));
			}
			if(x&1){
				if(lx&1);
				else if(min(t,f[i-1][1])+(a[i]-1-a[i-1])>=t)upd(i,0,1,min(t,f[i-1][1])+(a[i]-a[i-1])-t);
			}
			else {
				if(lx&1);
				else upd(i,0,1,min(t,f[i-1][1])+(a[i]-a[i-1]));
			}
		}
		lx=x;
	}
	if(f[m][0]<0&&f[m][1]<0)pc('N'),pc('o'),pc('\n');
	else {
		pc('Y'),pc('e'),pc('s'),pc('\n');
		if(f[m][0]>=0)Print(0);
		else Print(1);
	}
	fwrite(wbuf,1,p2,stdout);
}