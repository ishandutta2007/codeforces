#include <bits/stdc++.h>
#define ll long long
using namespace std;

void countDistinct(int arr[], int k, int n)
{
    int ans=INT_MAX;
    map<int, int> freq;
    int dist_count=0;
    for (int i=0; i<k; i++) {
        if (freq[arr[i]]==0) dist_count++;
        freq[arr[i]]++;
    }
    ans=min(ans, dist_count);
    for (int i=k; i<n; i++) {
        if (freq[arr[i-k]]==1) dist_count--;
        freq[arr[i-k]]--;
        if (freq[arr[i]]==0) dist_count++;
        freq[arr[i]]++;
        ans=min(ans, dist_count);
    }
    cout<<ans<<endl;
}

int32_t main()
{
    int q; cin>>q; while(q--) {
        int n, k, d; cin>>n>>k>>d; int a[n]; for(int i=0; i<n; i++) cin>>a[i];
        countDistinct(a, d, n);
    }
}