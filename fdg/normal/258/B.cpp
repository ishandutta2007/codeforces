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

vector <int > v;

int dp[15][15][2];

int find(int pos,int h,bool less) {
    if (dp[pos][h][less]!=-1) return dp[pos][h][less];
    if (pos==v.size()) return h==0;
    int res=0;
    for(int i=0;i<(less ? 10 : v[pos]+1);++i) {
        res+=find(pos+1,h-(i==4||i==7),less ? true : (i<v[pos]));
    }
    return dp[pos][h][less]=res;
}

int mod=1000000007;

int mPow(int a,int x) {
    int ret=1;
    while(x) {
        if (x&1) ret=1LL*ret*a%mod;
        a=1LL*a*a%mod; x>>=1;
    }
    return ret;
}

int inv(int x) {
    return mPow(x,mod-2);
}

int C(int n,int k) {
    if (n<k) return 0;
    int res=1;
    for(int i=1;i<=k;++i) {
        res=1LL*res*(n-i+1)%mod;
//      res=1LL*res*inv(i)%mod;
    }
    return res;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int m;
    cin >> m;
    while(m) {
        v.push_back(m%10);
        m/=10;
    }
    reverse(v.begin(),v.end());
    memset(dp,-1,sizeof(dp));
    int vals[11]={0};
    for(int i=0;i<10;++i) {
        vals[i]=find(0,i,false);
//      cout << i << "  " << find(0,i,false) << endl;
    }
    vals[0]--;
    int sum=0,ans=0;
    int cnt[10]={0};
    for(int a=0;a<10;++a) {
        for(int b=0;b<a;++b)
            for(int c=0;c+b<a;++c)
                for(int d=0;d+c+b<a;++d)
                    for(int e=0;e+d+c+b<a;++e)
                        for(int f=0;f+e+d+c+b<a;++f)
                            for(int g=0;g+f+e+d+c+b<a;++g) {
                                memset(cnt,0,sizeof(cnt));
                                cnt[a]++; cnt[b]++; cnt[c]++; cnt[d]++;
                                cnt[e]++; cnt[f]++; cnt[g]++;
                                int cur=1;
                                for(int i=0;i<10;++i)
                                    cur=1LL*cur*C(vals[i],cnt[i])%mod;
                                ans=(ans+cur)%mod;
                            }
    }
    /*for(int i=0;i<10;++i) {
        ans=(ans+1LL*vals[i]*C(sum,6))%mod;
        sum+=vals[i];
    }*/
    cout << ans << endl;
    return 0;
}