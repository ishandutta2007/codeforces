#include<bits/stdc++.h>
using namespace std;
const int Mxdt=100000;
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
int T,n,a[200005];map<long long,long long>mp;
long long sum=0;
int main(){
	T=read()+1;
	while(--T){
		n=read();sum=0;mp.clear();int opt=0;
		for(int i=1;i<=n;++i)a[i]=read(),sum+=a[i],++mp[a[i]];
		long long now=sum,a0=1,a1=0;
		while(sum){
			if(mp[sum]){
				int del=min(a0,mp[sum]);
				a0-=del,mp[sum]-=del;
			}
			if(mp[sum+1]){
				int del=min(a1,mp[sum+1]);
				a1-=del,mp[sum+1]-=del;
			}
			if(sum&1)a1=a1*2+a0;
			else a0=a0*2+a1;sum/=2;
			if(!a0&&!a1)break;
		}
		if(!sum&&mp[1]){
			int del=min(a1,mp[1]);
			a1-=del;mp[1]-=del;
		}
		if(!opt){
			if(a0||a1){
				puts("NO");opt=1;
			}
			if(!opt){
				for(int i=1;i<=n;++i){
					if(mp[a[i]]){
						puts("NO");opt=1;break;
					}
				}	
			}	
		}
		if(!opt)puts("YES");
	}
	return pc(0,1);
}