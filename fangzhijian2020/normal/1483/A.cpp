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
int T,n,m,k,tmp[100005];vector<int>v[100005];
int main(){
	T=read()+1;
	while(--T){
		n=read();m=read();
		for(int i=1;i<=n;++i)tmp[i]=0;
		for(int i=1;i<=m;++i){
			k=read();v[i].clear();
			for(int j=1;j<=k;++j){
				v[i].push_back(read());
			}
			if(k==1)++tmp[v[i][0]];
		}
		int opt=1;
		for(int i=1;i<=n;++i){
			if(tmp[i]>(m+1)/2){
				puts("NO");opt=0;
			}
		}
		if(opt){
			puts("YES");
			for(int i=1;i<=m;++i){
				if(v[i].size()==1){
					cout<<v[i][0]<<" ";
				}
				else{
					for(int j=0;j<v[i].size();++j){
						if(tmp[v[i][j]]<(m+1)/2){
							cout<<v[i][j]<<" ";
							++tmp[v[i][j]];break;
						}
					}
				}
			}
			puts("");
		}
	}
	return pc(0,1);
}