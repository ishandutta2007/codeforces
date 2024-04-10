#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int _,n,s[18][200005];
int main(){
    for (int i=1;i<=200000;i++){
        for (int j=0;j<=17;j++){
            s[j][i]=s[j][i-1];
            if (!((i>>j)&1)) s[j][i]++;
        }
    }
    scanf("%d",&_);
    while (_--){
        int l,r;
        scanf("%d%d",&l,&r); l--;
        int ans=r-l;
        for (int i=0;i<=17;i++) ans=min(ans,s[i][r]-s[i][l]);
        printf("%d\n",ans);
    }
    return 0;
}