#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int N,a[MAXN];
int main()
{
    cin>>N;For(i,1,N)cin>>a[i];sort(a+1,a+N+1);
    cout<<(N-1>>1)<<endl;For(i,1,N)cout<<(i&1?a[(N>>1)+(i+1>>1)]:a[i>>1])<<" \n"[i==N];return 0;
}