#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int a[400005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = n;i<2*n;i++){
        a[i] = a[i-n];
    }
    int cnt = 0;
    int ans = 0;
    for(int i =0;i<2*n;i++){
        if(a[i]==1)cnt++;
        else cnt=0;
        ans  = max(ans,cnt);
    }
    printf("%d\n",ans);
}