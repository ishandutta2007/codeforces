#include <bits/stdc++.h>

using namespace std;

const int MAXM = 101;
const int mod = 1000*1000*1000+7;

long long n;
int m;
int M[MAXM][MAXM];
int c[MAXM][MAXM];
int ans[MAXM][MAXM];
int result;

void product(int a[][MAXM], int b[][MAXM]) {
    for(int i=0; i<m;i++) for(int j=0; j<m;j++) c[i][j]=0;
    for(int i=0; i<m;i++) {
        for(int j=0; j<m;j++) {
            for(int z=0; z<m; z++) {
                c[i][j] = (c[i][j] + (long long)a[i][z]*b[z][j])%mod;
            }
        }
    }
}

void fastPower() {
    for(int i=0; i<m;i++) ans[i][i] = 1;
    while(n>0) {
        if(n&1) {
            product(ans,M);
            for(int i=0; i<m;i++) for(int j=0; j<m;j++) {
                ans[i][j]=c[i][j];
            }
        }
        product(M,M);
        for(int i=0; i<m;i++) for(int j=0; j<m;j++) M[i][j]=c[i][j];
        n/=2;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    if(n<m) {cout<<"1"; return 0;}
    for(int i=1; i<m;i++) {
        M[i][i-1]=1;
    }
    M[m-1][m-1]=1; M[0][m-1]=1;
    fastPower();
    for(int i=0; i<m;i++) result=(result+ans[i][0])%mod;
    cout<<result;
    return 0;
}