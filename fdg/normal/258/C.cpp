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

int n;
int arr[100005],sum[100005];
int mod=1000000007;
int divs[100005];
int ans=0;
int pd[50],cnt;
int d[5000],ds;

void find(int pos,int val) {
    if (pos==cnt) {
        d[ds++]=val;
        return;
    }
    int mx=pos+1;
    while(mx<cnt&&pd[mx]==pd[pos]) ++mx;
    find(mx,val);
    for(int i=pos;i<mx;++i) {
        val*=pd[i];
        find(mx,val);
    }
}

int mPow(int a,int x) {
    int ret=1;
    while(x) {
        if (x&1) ret=1LL*ret*a%mod;
        a=1LL*a*a%mod; x>>=1;
    }
    return ret;
}

int go(int n) {
    cnt=0; int N=n;
    while(n>1) {
        pd[cnt++]=divs[n];
        n/=divs[n];
    }
    sort(pd,pd+cnt);
    ds=0;
    find(0,1);
    sort(d,d+ds);
    int last=0,val=1,up=sum[100001];
    for(int i=0;i<ds;++i) {
        int c=(i==ds-1 ? up : sum[d[i+1]-1])-sum[d[i]-1];
        if (i==ds-1) {
            val=1LL*val*(mPow(i+1,c)-mPow(i,c))%mod;
            if (val<0) val+=mod;
        } else val=1LL*val*mPow(i+1,c)%mod;
    }
    return val;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;++i) {
        scanf("%d",&arr[i]);
        sum[arr[i]]++;
    }
    sort(arr,arr+n);
    int mx=arr[n-1];
    for(int i=1;i<=100001;++i)
        sum[i]+=sum[i-1];
    for(int i=2;i<=100000;++i)
        if (divs[i]==0) {
            divs[i]=i;
            for(int j=i+i;j<=100000;j+=i)
                if (divs[j]==0) divs[j]=i;
        }
    mx=100000;
    for(int i=1;i<=mx;++i) {
        ans+=go(i);
//      cout << res[i] << endl;
        if (ans>=mod) ans-=mod;
    }
    cout << ans << endl;
    return 0;
}