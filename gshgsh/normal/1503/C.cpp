#include<algorithm>
#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Pair pair<int,int>
#define F first
#define S second
#define MAXN 100001
int N;Pair a[MAXN];ll ans;
int main(){cin>>N;For(i,1,N)cin>>a[i].F>>a[i].S,ans+=a[i].S;sort(a+1,a+N+1);int mx=a[1].F+a[1].S;For(i,2,N)ans+=max(a[i].F-mx,0),mx=max(mx,a[i].F+a[i].S);cout<<ans<<endl;return 0;}