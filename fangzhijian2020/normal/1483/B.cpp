#include<bits/stdc++.h>
using namespace std;
const int Mxdt=100000;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
char pc(char c,bool opt){
	return (opt||putchar(c)),0;static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (opt||(*p1=++c,p1==p2))&&(fwrite(buf,1,p1-buf,stdout),p1=buf),0;
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
int T,n,a[100005],ans[100005],tot,vis[100005],pre[100005],suf[100005];queue<int>q;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void del(int x){
	++vis[suf[x]];
	q.push(suf[x]);
	ans[++tot]=x;
	suf[pre[x]]=suf[x];
	pre[suf[x]]=pre[x];
}
int main(){
	T=read()+1;
	while(--T){
		n=read();tot=0;while(!q.empty())q.pop();
		for(int i=1;i<=n;++i)a[i]=read();
		for(int i=1;i<=n;++i){
			pre[i]=i-1;suf[i]=i+1;
		}
		pre[1]=n;suf[n]=1;
		for(int i=2;i<=n;++i)q.push(i),vis[i]=1;q.push(1);vis[1]=1;
		while(!q.empty()){
			int x=q.front();q.pop();--vis[x];
			if(vis[x])continue;
			if(pre[x]==x){
				if(a[x]==1)ans[++tot]=x;
				break;
			}
			if(gcd(a[x],a[pre[x]])==1)del(x);
		}
		cout<<tot<<" ";
		for(int i=1;i<=tot;++i)cout<<ans[i]<<" ";
		puts("");
	}
	return pc(0,1);
}