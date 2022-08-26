#include<bits/stdc++.h>
#define maxn 500

using namespace std;
int n,a[maxn],k,x[maxn],y[maxn];

int main(){
    cin >> n;
    for (int i=1;i<=2*n;i++) cin >> a[i];
    for (int i=1;i<=n*2;i++){
        if (x[a[i]]) y[a[i]]=i; else x[a[i]]=i;
    }
    for (int i=1;i<=n;i++) k+=y[i]-x[i]-1; k/=2;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (x[i]<x[j]&&y[i]>y[j]) k++;
    cout << k << endl;
}