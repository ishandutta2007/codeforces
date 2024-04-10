#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <set>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int mod=1000000007;
int n,m,k;

int convertTo(int column[]) {
    int ret=0;
    for(int i=0;i<k;++i)
        ret=ret*(m+1)+column[i];
    return ret;
}

void convertFrom(int val,int column[]) {
    for(int i=k-1;i>=0;--i)
        column[i]=val%(m+1),val/=(m+1);
}

unordered_map <int,int> dp[11][11];

void add(int & res,int a) {
    res+=a;
    if (res>=mod) res-=mod;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    if (n+m-1>k) {
        puts("0");
        return 0;
    }
    int arr[11][11]={0};
    bool was[12]={0};
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j) {
            scanf("%d",&arr[i][j]);
            was[arr[i][j]]=true;
        }
    if (n<m) {
        int a[11][11]={0};
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                a[j][i]=arr[i][j];
        memcpy(arr,a,sizeof(arr));
        swap(n,m);
    }
    int tmp[12]={0},tmp2[12];
    for(int i=0;i<k;++i) tmp[i]=m;
    dp[0][0][convertTo(tmp)]=1;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j) {
//          cout << dp[i][j].size() << endl;
//          cout.flush();
            int ni=i,nj=j+1;
            if (nj==m) nj=0,ni++;
            for(unordered_map <int,int>::iterator it=dp[i][j].begin();it!=dp[i][j].end();++it) {
                if (it->second) {
                    convertFrom(it->first,tmp2);
                    if (arr[i][j]) {
                        if (tmp2[arr[i][j]-1]>j) {
                            tmp2[arr[i][j]-1]=j;
                            add(dp[ni][nj][convertTo(tmp2)],it->second);
                        }
                    } else {
                        bool ok=false;
                        for(int t=1;t<=k;++t) {
                            if (tmp2[t-1]<=j||ok&&tmp2[t-1]==m&&!was[t]) continue;
                            int vv=tmp2[t-1]; tmp2[t-1]=j;
                            add(dp[ni][nj][convertTo(tmp2)],it->second);
                            tmp2[t-1]=vv;
                            if (tmp2[t-1]==m&&!was[t]) ok=true;
                        }
                    }
                }
            }
        }
    int ans=0;
    int nwas=0;
    for(int i=1;i<=k;++i)
        if (!was[i]) {
            ++nwas;
        }
    for(unordered_map <int,int>::iterator it=dp[n][0].begin();it!=dp[n][0].end();++it) {
        convertFrom(it->first,tmp2);
        int cnt=0;
        for(int i=0;i<k;++i)
            if (tmp2[i]!=m) ++cnt;
        int val=it->second;
        for(int i=0;i<cnt-(k-nwas);++i)
            val=1LL*val*(nwas-i)%mod;
        add(ans,val);
    }
    printf("%d\n",ans);
    return 0;
}