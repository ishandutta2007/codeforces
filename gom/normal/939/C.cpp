#include <bits/stdc++.h>
#define N 100005
using namespace std;
long long n,a[N],b[N],s,f,ans,num,curr;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cin>>s>>f;
    for(int i=1;i<=f-s;i++)
        ans+=a[i];
    num=s;
    curr=ans;
    for(int i=2;i<=n;i++){
        curr-=a[(i+n-2)%n+1];
        curr+=a[(i+n+f-s-2)%n+1];
        if(ans<=curr){
            if(ans<curr)
                num=(s+n-i)%n+1;
            else
                num=min(num,(s+n-i)%n+1);
            ans=curr;
        }
    }
    cout<<num;
    return 0;
}