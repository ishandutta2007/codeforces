#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int>pi;
const int maxn=1e6+10;
const int M=1000000007;
int p2[maxn],n,a[maxn],cnt[34];
void sub(int &x,int y){x-=y;if (x<0) x+=M;}
int main(){
    cin >> n;
    p2[0]=1; for (int i=1;i<=n;i++) p2[i]=p2[i-1]*2%M;
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        int r=0;
        while (a[i]%2==0) a[i]>>=1,r++;
        cnt[r]++;
    }
    int sum=0;
    int ans=p2[n]-1;
    for (int i=30;i;i--){
        if (!cnt[i]) continue;
        sum+=cnt[i];
        sub(ans,p2[sum-1]);
    }
    printf("%d\n",ans);
    return 0;
}