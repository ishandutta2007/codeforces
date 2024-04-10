#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
#include <memory.h>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#pragma comment(linker,"/STACK:128000000")

using namespace std;

bool prime[100002];
vector <int> pr;
int ans=0,index[100002];

int mat[6][6];

void go(int cur,int len) {
    if (cur==len) {
        ++ans;
        return;
    }
    int mn=0,mx=0,rr=0;
    for(int i=0;i<cur;++i)
        mn=mn*10+mat[cur][i];
    for(int i=cur;i<len;++i)
        mn*=10,rr=rr*10+9;
    mx=mn+rr;
    int L,R;
/*  int l=-1,r=pr.size();
    while(r-l>1) {
        int m=(l+r)/2;
        if (pr[m]>=mn) r=m;
        else l=m;
    }*/
    L=index[mn];
/*  l=-1,r=pr.size();
    while(r-l>1) {
        int m=(l+r)/2;
        if (pr[m]>mx) r=m;
        else l=m;
    }
    R=l;*/
    for(int i=L;i<pr.size()&&pr[i]<=mx;++i) {
        int p=pr[i];
        for(int j=len-1;j>=cur;--j) {
            mat[cur][j]=mat[j][cur]=p%10; p/=10;
        }
        go(cur+1,len);
    }
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    for(int i=2;i<=10000;++i) {
        if (!prime[i])
            for(int j=i*i;j<=100000;j+=i)
                prime[j]=true;
    }
    int cnt=0;
    for(int i=2;i<=100000;++i) {
        if (!prime[i]) {
            ++cnt;
            pr.push_back(i);
        }
    }
    index[100001]=100001;
    int it=pr.size()-1;
    for(int i=100000;i>=2;--i) {
        if (!prime[i]) index[i]=it,--it;
        else index[i]=index[i+1];
    }
    int T,p;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&p); ans=0;
        int len=1,l=1,r=10;
        while(true) {
            if (p>=l&&p<r) break;
            len++; l*=10; r*=10;
        }
        for(int i=len-1;i>=0;--i) {
            mat[0][i]=mat[i][0]=p%10; p/=10;
        }
        go(1,len);
        cout << ans << endl;
    }
//  for(int i=0;i<30;++i)
//      cout << pr[9500+i] << endl;
//  cout << clock() << endl;
    return 0;
}