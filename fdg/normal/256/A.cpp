#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#pragma comment (linker,"/STACK:256000000")

using namespace std;

int dp[4002][4002];
int nx[4002][4002];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,arr[4002],arr2[4002];
    cin >> n;
//  n=4000;
    for(int i=0;i<n;++i) {
        cin >> arr[i];
//      arr[i]=rand();
        arr2[i]=arr[i];
    }
    for(int i=0;i<=n;++i)
        nx[n][i]=n;
    for(int i=0;i<n;++i) {
        nx[i][n]=nx[i][n-1]=n;
        for(int j=n-2;j>=0;--j) {
            nx[i][j]=nx[i][j+1];
            if (arr[i]==arr[j+1]) {
                nx[i][j]=j+1;
            }
        }
    }
    dp[n][n]=0;
    for(int i=n-1;i>=0;--i) {
        dp[i][n]=1;
        for(int j=i+1;j<n;++j)
            dp[i][j]=2+dp[nx[i][j]][nx[j][nx[i][j]]];
    }
    int ans=1;
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j)
            ans=max(ans,dp[i][j]);
    cout << ans << endl;
    /*map <int,int> f; int ans=0;
    set <int> last;
    for(int i=0;i<k;++i) {
        f.clear(); last.clear();
        for(int j=0;j<n;++j) {
            if (arr[j]==arr2[i]) {
                for(set <int>::iterator it=last.begin();it!=last.end();++it)
                    f[*it]++;
                last.clear();
            } else {
                if (!last.count(arr[j])) {
                    f[arr[j]]++;
                    last.insert(arr[j]);
                }
            }
        }
        for(map <int,int>::iterator it=f.begin();it!=f.end();++it)
            ans=max(ans,it->second);
    }
    cout << ans << endl;*/
    return 0;
}