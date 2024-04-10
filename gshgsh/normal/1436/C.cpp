#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define mid (l+r>>1)
#define P 1000000007
int N,x,pos,a,b;int A(int x,int y){int ans=1;For(i,x-y+1,x)ans=1ll*ans*i%P;return ans;}
int main(){cin>>N>>x>>pos;int l=0,r=N;while(l<r)mid>pos?a++,r=mid:(b+=mid!=pos,l=mid+1);cout<<1ll*A(N-x,a)*A(x-1,b)%P*A(N-a-b-1,N-a-b-1)%P<<endl;return 0;}