#include<bits/stdc++.h>
#define maxn 5000000

using namespace std;
typedef long long ll;
const int M=18;
ll p,l,r,k,n,b[19],c[19],u,v,ans,res,d[19],g;
int a[maxn][10];
//int t[maxn][10];
bool f[maxn];

bool c2(int x,int y,int res)
{
    for (int i=1;i<10;i++) d[i]=a[x][i];
    if (b[y]>0){
        if (!d[b[y]]) return false;
        d[b[y]]--;
    }
    else {
        res--;
        if (a[x][0]>res) return false;
    }
    for (int i=y-1;i;i--){
        for (int w=b[i]+1;w<10;w++) if (d[w]) return true;
        if (b[i]==0) {
            res--;
            if (a[x][0]>res) return false;
        }
        else {
            if (!d[b[i]]) return false;
            d[b[i]]--;
        }
    }
    if (b[0]==0) return true;
    for (int w=b[0];w<10;w++) if (d[w]) return true; return false;
}

bool c1(int x,int y,int res)
{
    for (int i=1;i<10;i++) d[i]=a[x][i];
    if (!d[c[y]]) return false; d[c[y]]--;
    for (int i=y-1;i;i--){
        for (int w=1;w<c[i];w++) if (d[w]) return true;
        if (c[i]==0) {
            res--;
            if (a[x][0]>res) return false;
        }
        else {
            if (a[x][0]<res) return true;
            if (!d[c[i]]) return false;
            d[c[i]]--;
        }
    }
    if (a[x][0]<res) return true;
    if (c[0]==0) {
        res--;
        if (a[x][0]>res) return false;
    }
    else {
        for (int w=1;w<=c[0];w++) if (d[w]) return true; return false;
    }
}

bool check(int x)
{
    res=18;
    int j=17;
    while (b[j]==c[j]){
        if (b[j]==0) res--;
        else {
            if (!a[x][b[j]]) return false;
            a[x][b[j]]--;
        }
        j--;
    }
    if (a[x][0]>res) return false;
    for (int i=b[j]+1;i<c[j];i++) if (a[x][i]) return true;
    if (c2(x,j,res)) return true;
    if (c1(x,j,res)) return true;
    return false;
}

int main()
{
    while (true){
        for (int j=0;j<10;j++) a[p+1][j]=a[p][j]; p++;
        if (a[p][0]==M){
            int j=1; while (!a[p][j]) j++;
            a[p][0]-=a[p][j]-1; a[p][j]=0; a[p][j+1]++;
        }
        else{
            a[p][1]++; a[p][0]++;
        }
        if (a[p][9]==M) break;
    }
    //for (int i=1;i<=p;i++) for (int j=1;j<10;j++) t[i][j]=a[i][j];
    cin >> l >> r;
    if (l/10==r/10) {
        cout << r-l+1 << endl;
        return 0;
    }
    if (r==1000000000000000000ll) ans=1,r--;
    while (l) b[u++]=l%10,l/=10;
    while (r) c[v++]=r%10,r/=10;
    for (int i=1+ans;i<=p;i++)
        if (check(i)){
            ans++;
            //for (int j=1;j<10;j++) cout << t[i][j] << ' '; cout << i << endl;
        }
    cout << ans << endl;
    return 0;
}