#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[1000005],mn[1000005],vst[1000005],st[1000005],top;
basic_string<int> pos[1000005],ss[1000005],uu[1000005];
ll ans=0;
char str[1000005];
int p1=1000000;
char buf[1000005];
int gc(){
	if(p1>=1000000)fread(buf,1,1000000,stdin),p1=0;
	return buf[p1++];
}
int rd(){
	int x=0;
	char ch=gc();
	while(ch<'0'||ch>'9')ch=gc();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=gc();
	return x;
}
char GN(){
	char ch=gc();
	while(ch!='*'&&ch!='/')ch=gc();
	return ch;
}
struct Heap{
	priority_queue<int,vector<int>,greater<int>> q,del;
	void push(int n){q.push(n);}
	void pop(int n){del.push(n);}
	int top(){
		while(q.size()&&del.size()&&q.top()==del.top())q.pop(),del.pop();
		return q.top();
	}
}q;
int main(){
	mn[1]=1;
	for(int i=2;i<=1000000;i++){
		if(vst[i])continue;
		pos[i].push_back(0),ss[i].push_back(0);
		mn[i]=i;
		if(1ll*i*i>1000000)continue;
		for(int j=i*i;j<=1000000;j+=i){
			vst[j]=1;
			if(!mn[j])mn[j]=i;
		}
	}
	n=rd();
	for(int i=1;i<=n;i++)a[i]=rd();
	for(int i=1;i<=n;i++)str[i]=GN();
	for(int i=1;i<=n;i++){
		int x=a[i];
		while(x!=1){
			int p=mn[x],cnt=0;
			while(x%p==0)x/=p,cnt++;
			if(str[i]=='*')ss[p].push_back(cnt);
			else ss[p].push_back(-cnt);
			pos[p].push_back(i);
		}
	}
	for(int i=2;i<=1000000;i++){
		if(pos[i].size()<=1)continue;
		int sum=0;
		auto v=pos[i],vv=ss[i];
		for(int j=0;j<v.size();j++)vv[j]=sum=sum+vv[j];
		v.push_back(n+1),vv.push_back(-1e9);
		st[top=1]=v.size()-1;
		for(int j=v.size()-2;j>=0;j--){
			while(top&&vv[st[top]]>=vv[j])top--;
			if(top)uu[v[j]+1].push_back(v[st[top]]-1),uu[v[j+1]+1].push_back(v[st[top]]-1-2000000);
			st[++top]=j;
		}
	}
	uu[1].push_back(n);
	for(int i=1;i<=n;i++){
		for(int j:uu[i])if(j>=0)q.push(j);
		for(int j:uu[i])if(j<0)q.pop(j+2000000);
		ans+=q.top()-i+1;
	}
	cout<<ans;
}