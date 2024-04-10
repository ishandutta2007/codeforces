#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Pair pair<int,int>
#define F first
#define S second
#define MAXN 100001
int N;vector<Pair>ans;void sol(int l,int r){if(l==r)return;int mid=l+r>>1;sol(l,mid);sol(mid+1,r);For(i,l,mid)ans.push_back({i,i-l+mid+1});}
int main(){cin>>N;int k=0;while((1<<k+1)<=N)k++;sol(1,1<<k);sol(N-(1<<k)+1,N);cout<<ans.size()<<endl;for(auto v:ans)cout<<v.F<<' '<<v.S<<endl;return 0;}