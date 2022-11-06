#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int Mxdt=100000;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int T,n,m,ta[1000005],tb[1000005],ans;
struct node{
	int a,b,c,al,ar,len,id;
	bool operator<(const node&x)const{
		if(len!=x.len)return len<x.len;
		if(al!=x.al)return al<x.al;
		return ar<x.ar;
	}
}t[200005];
void solve(int i,int x){
//	cout<<t[i].id<<";\n";
	ta[t[i].id]=t[i].a-x;
	tb[t[i].id]=t[i].c-ta[t[i].id];
}
int main(){
	T=read()+1;
	while(--T){
		n=read();ans=0;
		for(int i=1;i<=n;++i){
			t[i].a=read();t[i].b=read();t[i].c=read();
			t[i].len=t[i].a+t[i].b-t[i].c;
			t[i].al=max(0,t[i].a-t[i].c);
			t[i].ar=min(t[i].a,t[i].a-(t[i].c-t[i].b));
			t[i].id=i;
		}
		sort(t+1,t+n+1);
		for(int i=1,Next=1;i<=n;i=Next){
			while(Next<=n&&t[i].len==t[Next].len)++Next;
			int Max=-1,tmp=0;
			for(int k=i;k<Next;++k){
				if(t[k].al<=Max){
					Max=min(Max,t[k].ar);
				}
				else{
					if(Max!=-1){
						for(int p=tmp;p<k;++p){
							solve(p,Max);
						}
					}
					Max=t[k].ar;tmp=k;++ans;
				}
			}
			if(Max!=-1){
				for(int p=tmp;p<Next;++p){
					solve(p,Max);
				}
			}
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;++i){
			cout<<ta[i]<<" "<<tb[i]<<"\n";
		}
	}
	return 0;
}