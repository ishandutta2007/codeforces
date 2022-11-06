#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
char c[1000005];int n,l,r,f[1000005],now,a[1000005];
int tot=1,last,len[1000005],fail[1000005],ch[1000005][26],del[1000005],jump[1000005],sum[1000005];
int newnode(int Len){
	len[++tot]=Len;return tot;
}
int get(int p){
	while(a[now]!=a[now-len[p]-1])p=fail[p];
	return p;
}
int Insert(int c){
	a[++now]=c;int p=get(last),q;
	if(!ch[p][c]){
		q=newnode(len[p]+2);
		fail[q]=ch[get(fail[p])][c];
		ch[p][c]=q;del[q]=len[q]-len[fail[q]];
		if(del[q]!=del[fail[q]])jump[q]=fail[q];
		else jump[q]=jump[fail[q]];
	}
	return last=ch[p][c];
}
int Mod(int x){return x<mod?x:x-mod;}
void Add(int&x,int y){x=Mod(x+y);} 
int main(){
	scanf("%s",c+1),a[0]=-1;
	n=strlen(c+1);l=1;r=n;f[0]=1;
	fail[0]=fail[1]=1;len[1]=-1;last=1;del[0]=1;
	while(l<=r){
		Insert(c[l++]-'a');
		for(int p=last;p;p=jump[p]){
			sum[p]=f[now-len[jump[p]]-del[p]];
			if(del[p]==del[fail[p]])Add(sum[p],sum[fail[p]]);
		}
		Insert(c[r--]-'a');
		for(int p=last;p;p=jump[p]){
			sum[p]=f[now-len[jump[p]]-del[p]];
			if(del[p]==del[fail[p]])Add(sum[p],sum[fail[p]]);
			Add(f[now],sum[p]);
		}
	}
	printf("%d\n",f[now]);
	return 0;
}
//abbababababbab
//abbabbabbaabba