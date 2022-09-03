#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
using namespace std;
char c[200005];
int dp(int l,int r,char val){
    if(l==r){
        if(c[l]==val)return 0;
        else return 1;
    }
    int mid=(l+r)/2;
    int cnt1=0,cnt2=0;
    for(int i = l;i<=r;i++){
        if(c[i]!=val){
            if(i<=mid)cnt1++;
            else cnt2++;
        }
    }
    return min(dp(l,mid,val+1)+cnt2,dp(mid+1,r,val+1)+cnt1);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        scanf("%s",c);
        printf("%d\n",dp(0,n-1,'a'));
    }
}