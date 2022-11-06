#include<bits/stdc++.h>
using namespace std;
const int Mxdt=100000,N=100000;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
char pc(char c,bool opt){
	return (opt||putchar(c)),0;static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (opt||(*p1++=c,p1==p2))&&(fwrite(buf,1,p1-buf,stdout),p1=buf),0;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
void print(int x){
	if(x>9)print(x/10);
	pc(x%10^48,0);
}
void printnum(int x,char c){
	if(x<0)pc('-',0),x=-x;
	print(x);pc(c,0);
}
int n,a[200005],B,ans;
const int M=9999991;
struct map{
	int H[M+1],cnt,to[2000005],Next[2000005];long long id[2000005];
	void clear(){
		while(cnt){
			H[(id[cnt]%M+M)%M]=0;
			to[cnt]=Next[cnt]=id[cnt]=0;--cnt;
		}
	}
	int&operator[](const long long&x){
		int p=(x%M+M)%M;
		for(int i=H[p];i;i=Next[i]){
			if(id[i]==x)return to[i];
		}
		++cnt;id[cnt]=x;Next[cnt]=H[p];H[p]=cnt;
		return to[cnt];
	}
}mp;
int main(){
	n=read();B=sqrt(2*N);
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=-B;i<=B;++i){
		mp.clear();
		for(int j=1;j<=n;++j){
			++mp[1ll*j*i+a[j]];
			ans=max(ans,mp[1ll*j*i+a[j]]);
		}
	}
	for(int i=1;i<=n;++i){
		mp.clear();
		for(int j=i+1;j<=min(n,i+B);++j){
			if((a[j]-a[i])%(j-i)==0){
				++mp[(a[j]-a[i])/(j-i)];
				ans=max(ans,mp[(a[j]-a[i])/(j-i)]+1);
			}
		}
	}
	cout<<n-ans<<'\n';
	return pc(0,1);
}