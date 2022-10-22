#include <bits/stdc++.h>
#define N 200005
using namespace std;
int n,a[N],plc[N],s[N];
string S;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        plc[a[i]]=i;
    }
    cin>>S;
    for(int i=1;i<=n-1;i++)
        s[i]=s[i-1]+S[i-1]-'0';
    for(int i=1;i<=n;i++){
        if(plc[i]==i)
            continue;
        if(plc[i]<i){
            if(s[i-1]-s[plc[i]-1]==i-plc[i])
                continue;
            printf("NO");
            return 0;
        }
        if(s[plc[i]-1]-s[i-1]==plc[i]-i)
            continue;
        printf("NO");
        return 0;
    }
    printf("YES");
    return 0;
}