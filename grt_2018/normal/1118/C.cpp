#include <bits/stdc++.h>

using namespace std;

const int MAXN = 401;

int n,ile1,ile2;
int a[MAXN];
int cnt[1001];
int T[21][21];

int main() {
    cin>>n;
    for(int i=0; i<n*n;i++) {
        cin>>a[i]; cnt[a[i]]++;
    }
    for(int i=1; i<=1000;i++) {
        if(cnt[i]%4==1) ile1++;
        if(cnt[i]%4==2) ile2++;
        if(cnt[i]%4==3) {
            ile1++;
            ile2++;
        }
    }
    if((n%2==0&&(ile1||ile2))) {cout<<"NO"; return 0;}
    if(n%2==1&&(ile1>1||ile2>(n/2)*2)) {cout<<"NO"; return 0;}
    int pos1=1,pos2=1;
    for(int i=1; i<=1000;i++) {
        while(cnt[i]>=4) {
            cnt[i]-=4;
            T[pos1][pos2] = T[n-pos1+1][pos2] = T[pos1][n-pos2+1] = T[n-pos1+1][n-pos2+1] = i;
            pos2++;
            if(pos2==n/2+1) {pos2=1; pos1++;}
            if(pos1>n/2) {i=1001; break;}
        }
    }
    if(n%2==1) {
    pos1=n/2+1; pos2=1; bool ok=1;
    for(int i=1; i<=1000;i++) {
        if(cnt[i]%2==1) {cnt[i]--; T[n/2+1][n/2+1]=i;}
        while(cnt[i]>0) {
            cnt[i]-=2;
            T[pos1][pos2] = T[n-pos1+1][pos2] = T[pos1][n-pos2+1] = T[n-pos1+1][n-pos2+1] = i;
            if(ok) pos2++;
            else pos1++;
            if(pos1==pos2&&pos2==n/2+1) {pos1=1; pos2=n/2+1;ok=0;}
        }
    }
    }
    cout<<"YES\n";
    for(int i=1; i<=n;i++) {
        for(int j=1; j<=n;j++) {
            cout<<T[i][j]<<" ";
        }
        cout<<"\n";
    }
}