#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int N,a[MAXN];
int main()
{
    cin>>N;For(i,1,N)cin>>a[i];sort(a+1,a+N+1);vector<int>ans(N+1);int j=1,k=(N>>1)+1;For(i,1,N)ans[i]=a[i&1?k++:j++];
    int cnt=0;For(i,2,N-1)cnt+=ans[i-1]>ans[i]&&ans[i+1]>ans[i];cout<<cnt<<endl;For(i,1,N)cout<<ans[i]<<" \n"[i==N];return 0;
}