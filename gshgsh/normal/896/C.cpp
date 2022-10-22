#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<set>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int N,M,seed,mxv;struct ODT{int l,r;mutable ll v;ODT(){}ODT(int x,int y,ll z){l=x,r=y,v=z;}bool operator<(const ODT&x)const{return l<x.l;}};set<ODT>odt;
int pow(int a,int b,int P){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
auto split(int x){if(x>N)return odt.end();auto y=--odt.upper_bound(ODT(x,0,0));if((*y).l==x)return y;int l=(*y).l,r=(*y).r;ll v=(*y).v;odt.erase(y);odt.insert(ODT(l,x-1,v));return odt.insert(ODT(x,r,v)).first;}
void assign(int l,int r,int v){auto y=split(r+1),x=split(l);odt.erase(x,y);odt.insert(ODT(l,r,v));}
void upd(int l,int r,int v){auto y=split(r+1),x=split(l);while(x!=y)(*x).v+=v,x++;}
ll ask1(int l,int r,int k){auto y=split(r+1),x=split(l);vector<pair<ll,int>>val;while(x!=y)val.push_back({(*x).v,(*x).r-(*x).l+1}),x++;sort(val.begin(),val.end());for(auto i:val)if(i.second>=k)return i.first;else k-=i.second;}
int ask2(int l,int r,int v,int P){auto y=split(r+1),x=split(l);int ans=0;while(x!=y)ans=(ans+1ll*((*x).r-(*x).l+1)*pow((*x).v%P,v,P))%P,x++;return ans;}
int rnd(){int tmp=seed;seed=(seed*7ll+13)%1000000007;return tmp;}
int main(){cin>>N>>M>>seed>>mxv;For(i,1,N)odt.insert(ODT(i,i,rnd()%mxv+1));For(i,1,M){int opt=rnd()%4+1,l=rnd()%N+1,r=rnd()%N+1,x;if(l>r)swap(l,r);x=opt==3?rnd()%(r-l+1)+1:rnd()%mxv+1;opt<=2?opt==1?upd(l,r,x):assign(l,r,x),0:(cout<<(opt==3?ask1(l,r,x):ask2(l,r,x,rnd()%mxv+1))<<'\n',0);}return 0;}