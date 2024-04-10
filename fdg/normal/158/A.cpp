#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
#include <memory.h>
#include <algorithm>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,k,arr[55]={0};
    cin >> n >> k;
    for(int i=0;i<n;++i) {
        cin >> arr[i];
        arr[i]=1000-arr[i];
    }
    sort(arr,arr+n);
    int ans=0;
    for(int i=0;i<n&&arr[i]!=1000;++i) {
        if (i<k||arr[i]==arr[k-1]) ans++;
        else break;
    }
    cout << ans << endl;
    return 0;
}