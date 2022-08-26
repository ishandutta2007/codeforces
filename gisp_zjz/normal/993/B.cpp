#include<bits/stdc++.h>
#define maxn 300000
#define F first
#define S second

using namespace std;
typedef pair<int,int> pi;
int n,m,c[25][25],d[10],r;
pi a[maxn],b[maxn];
bool f,g;

int main(){
    cin >> n >> m;
    for (int i=0;i<n;i++){
        cin >> a[i].F >> a[i].S;
        if (a[i].F>a[i].S) swap(a[i].F,a[i].S);
    }
    for (int i=0;i<m;i++){
        cin >> b[i].F >> b[i].S;
        if (b[i].F>b[i].S) swap(b[i].F,b[i].S);
    }
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++){
            r=-1;
            if (a[i].F==b[j].F&&a[i].S==b[j].S) continue;
            if (a[i].F==b[j].F) r=a[i].F;
            else if (a[i].S==b[j].S) r=a[i].S;
            else if (a[i].F==b[j].S) r=a[i].F;
            else if (a[i].S==b[j].F) r=a[i].S;
            c[i][j]=r;
            if (r!=-1) d[r]=1;
        }
    r=0; for (int i=1;i<10;i++) r+=d[i];
    if (r==1){for (int i=1;i<10;i++) if (d[i]) cout << i << endl;return 0;}
    for (int i=0;i<n;i++){
        r=-1;
        for (int j=0;j<m;j++) {
            if (c[i][j]<=0) continue;
            if (c[i][j]!=r){
                if (r==-1) r=c[i][j];
                else {cout << -1 << endl;return 0;}
            }
        }
    }
    for (int j=0;j<m;j++){
        r=-1;
        for (int i=0;i<n;i++) {
            if (c[i][j]<=0) continue;
            if (c[i][j]!=r){
                if (r==-1) r=c[i][j];
                else {cout << -1 << endl;return 0;}
            }
        }
    }
    cout << 0 << endl;
}