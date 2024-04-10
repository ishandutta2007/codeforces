#include <cstdio>
#include <cmath>
#include <iostream>
#define maxn 300005
int n;
int arr[maxn], sum[maxn], cnt[2]={0};
int popcounts(long long t) {
    if (t==0) return 0;
    return popcounts(t/2)+t%2;
}
int main() {
    long long t; sum[0]=0;
    std::cin >> n;
    for (int i=1;i<=n;++i) {
        std::cin>>t;
        arr[i]=popcounts(t);
        sum[i]=sum[i-1]+arr[i];
       // printf("%d ", arr[i]);
    } long long ans=0;
    for (int i=1;i<=n;++i) {
        if (arr[i]==0) ans++;
        if (sum[i]%2==0) ans+=cnt[0];
        else ans+=cnt[1];
        cnt[sum[i-1]%2]++; int max=arr[i];
        for (int j=2;j<=64&&i-j>=0;++j) {
            max=std::max(max, arr[i-j+1]);
            if ((sum[i]-sum[i-j])%2==0&&max>(sum[i]-sum[i-j])/2) {
                ans--;// printf("!");
            }
        }
        //printf("%d %d\n", cnt[0], cnt[1]);
    }std::cout << ans;
    return 0;
}