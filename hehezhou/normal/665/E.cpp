#include<bits/stdc++.h>
using namespace std;
typedef bitset<32> bs;
int a[32000000][2],size[32000000],tot,n,root;
long long ans;
unsigned long s[1000010],k;
void add(int& now,int t,bs& x){
	if(now==0)now=++tot;
	size[now]++;
	if(t==-1)return;
	add(a[now][x[t]],t-1,x);
}
int query(int now,int t,bs& x,bs& k){//x^y>=k,cnt(y)
	if(now==0)return 0;
	if(t==-1)return size[now];
	if(k[t]==0)return size[a[now][x[t]^1]]+query(a[now][x[t]],t-1,x,k);
	else return query(a[now][x[t]^1],t-1,x,k);
}
int main(){
	scanf("%d%lu",&n,&k);
	bs _k(k),_0(0);
	add(root,30,_0);
	for(int i=1;i<=n;i++){
		scanf("%lu",&s[i]);
		s[i]^=s[i-1];
		bs _si(s[i]);
		ans+=query(root,30,_si,_k);
		add(root,30,_si);
	}
	return printf("%lld\n",ans),0;
}