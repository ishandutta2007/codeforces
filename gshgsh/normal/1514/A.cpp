#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
int T,N,a[MAXN];bool check(int x){int i=1;while(i*i<x)i++;return i*i!=x;}
int main(){cin>>T;while(T--){cin>>N;For(i,1,N)cin>>a[i];bool flag=0;For(i,1,N)if(check(a[i])){cout<<"YES\n";flag=1;break;}if(!flag)cout<<"NO\n";}return 0;}