#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int N,a[MAXN];
int main()
{
	cin>>N;For(i,1,N)cin>>a[i];int cnt=0;ll now=0;priority_queue<int>q;
	For(i,1,N){if(a[i]>=0)cnt++,now+=a[i];else cnt++,now+=a[i],q.push(-a[i]);if(now<0)cnt--,now+=q.top(),q.pop();}
	cout<<cnt<<endl;return 0;
}