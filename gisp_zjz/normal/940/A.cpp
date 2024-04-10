#include<bits/stdc++.h>

using namespace std;
int ans,n,cnt[105],k,m,d;

int main()
{
    scanf("%d%d",&n,&d);
    for (int i=0;i<n;i++){
        scanf("%d",&k);
        cnt[k]++;
    }
    for (int i=0;i+d<=100;i++)
    {
        m=0;
        for (int j=0;j<=d;j++) m+=cnt[i+j];
        ans=max(m,ans);
    }
    cout << n-ans << endl;
}