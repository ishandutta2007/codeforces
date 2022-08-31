#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int M=1000000007;
const int maxn=1000006;
int n,k,a[maxn],cnt[maxn],ans,x,y,_;
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;i++) cnt[i]=0;
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }
        for (int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
        ans=n+1;
        int r=1,nd=(n+k+1)/2;
        for (int l=0;l<n;l++){
            if (cnt[l]+nd>n) break;
            while (cnt[l]+nd>cnt[r]) ++r;
            if (r-l<ans) ans=r-l,x=l+1,y=r;
        }
        printf("%d %d\n",x,y);
        int pos=0,sum=0;
        for (int i=1;i<k;i++){
            int L=pos+1;
            while (sum<i){
                pos++;
                if (a[pos]>=x&&a[pos]<=y) sum++; else sum--;
            }
            printf("%d %d\n",L,pos);
        }
        printf("%d %d\n",pos+1,n);
    }
    return 0;
}