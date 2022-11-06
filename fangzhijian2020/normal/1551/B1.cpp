#include<iostream> 
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int T,n,t[100005],h[100005];char c[100005];
priority_queue<int>q;
bool check(int L){
	if(L==0)return 1;while(!q.empty())q.pop();
	for(int i=0;i<26;++i)if(h[i])q.push(h[i]);
	int tp=0,tot=0,x;
	while(!q.empty()){
		x=q.top();q.pop();
		if(x>1)t[++tot]=x-1;++tp;if(tp==L)break;
	}
	for(int i=1;i<=tot;++i)q.push(t[i]);
	if(tp!=L)return 0;tp=0;
	while(!q.empty()){
		x=q.top();q.pop();
		++tp;if(tp==L)break;
	}
	if(tp!=L)return 0;return 1;
}
int main(){
	T=read()+1;
	while(--T){
		scanf("%s",c+1);n=strlen(c+1);
		for(int i=1;i<=n;++i){
			++h[c[i]-'a'];
		}
		int l=0,r=26;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid))l=mid+1;
			else r=mid-1;	
		}
		cout<<l-1<<"\n";
		for(int i=1;i<=n;++i){
			h[c[i]-'a']=0;
		}
//		check(l-1);
	}
	return 0;
}