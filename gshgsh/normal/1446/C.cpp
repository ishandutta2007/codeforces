#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,a) for(auto i:a)
#define arr vector<int>
int N;arr a;int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int sol(arr a,int now){if(now<0||a.size()<=3)return 0;arr v[2];For(i,a)v[(i>>now)&1].push_back(i);return min(sol(v[0],now-1)+max(v[1].size()-1ll,0ll),sol(v[1],now-1)+max(v[0].size()-1ll,0ll));}
int main(){N=get();while(N--)a.push_back(get());cout<<sol(a,30)<<endl;return 0;}