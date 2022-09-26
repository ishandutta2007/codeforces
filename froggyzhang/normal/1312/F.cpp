#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
typedef vector<vector<int> > vt;
typedef long long ll;
#define N 300030
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int T,n,x,y,z,vis[5],pre,len; 
ll a[N];
vt sg;
map<vt,int> mp;
inline int mex(int a,int b,int c){
	memset(vis,0,sizeof(vis));
	vis[a]=vis[b]=vis[c]=1;
	for(int i=0;;++i){
		if(!vis[i])return i;
	}
} 
void Add(){
	vector<int> tmp(3,0);
	int tot=sg.size();
	tmp[0]=mex(sg[max(tot-x,0)][0],sg[max(tot-y,0)][1],sg[max(tot-z,0)][2]);
	tmp[1]=mex(sg[max(tot-x,0)][0],4,sg[max(tot-z,0)][2]);
	tmp[2]=mex(sg[max(tot-x,0)][0],sg[max(tot-y,0)][1],4);
	sg.push_back(tmp);
}
inline int Get(ll x){
	return x<pre?x:(x-pre)%len+pre;
}
int main(){
	T=read();
	while(T--){
		n=read(),x=read(),y=read(),z=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		sg.clear(),mp.clear();
		sg.push_back({0,0,0});
		for(int i=1;i<5;++i){
			Add();
		}
		while("MYH AK IOI!!!"){
			vt tmp(sg.end()-5,sg.end());
			if(mp.count(tmp)){
				pre=mp[tmp],len=sg.size()-5-pre;
				break;
			}
			mp[tmp]=sg.size()-5;
			Add();
		}
		int sum=0,s[4]={0,0,0,0};
		for(int i=1;i<=n;++i){
			ll v0=max(a[i]-x,0LL),v1=max(a[i]-y,0LL),v2=max(a[i]-z,0LL);
			int now=sg[Get(a[i])][0],X=sg[Get(v0)][0],Y=sg[Get(v1)][1],Z=sg[Get(v2)][2];
			sum^=now;
			++s[now^X],++s[now^Y],++s[now^Z];
		}
		printf("%d\n",s[sum]);
	}
	return 0;
}