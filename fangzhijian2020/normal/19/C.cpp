#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int base=1e9+7;
unsigned long long mi[100005],Hash[100005];
int n,a[100005],tmp,len,ans,tot;map<int,int>Pre,Next;
struct node{
	int len,x;
	bool operator<(const node &a)const{
		if(len==a.len)return x<a.x;
		return len<a.len;
	}
}q[100005];
unsigned long long get_Hash(int l,int r){
	return Hash[r]-Hash[l-1]*mi[r-l+1];
}
int main(){
	scanf("%d",&n);mi[0]=1;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(Pre.find(a[i])!=Pre.end()){
			Next[Pre[a[i]]]=i;
		}
		Pre[a[i]]=i;mi[i]=mi[i-1]*base;
		Hash[i]=Hash[i-1]*base+a[i];
	}
	for(int i=1;i<=n;++i){
		if(Next.find(i)==Next.end())continue;
		tmp=Next[i];len=tmp-i;
		while(tmp+len-1<=n){
			if(get_Hash(i,tmp-1)==get_Hash(tmp,tmp+len-1)){
				q[++tot]=(node){len,i};break;
			}
			if(Next.find(tmp)==Next.end())break;
			tmp=Next[tmp];len=tmp-i;
		}
	}
	sort(q+1,q+tot+1);ans=0;
	for(int i=1;i<=tot;++i){
		if(q[i].x>ans){
			ans=q[i].x+q[i].len-1;
		}
	}
	printf("%d\n",n-ans);
	for(int i=ans+1;i<=n;++i)printf("%d ",a[i]);
	return 0;
}