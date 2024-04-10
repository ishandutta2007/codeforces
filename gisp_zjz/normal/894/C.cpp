#include<bits/stdc++.h>
#define maxn 1050

using namespace std;
int a[maxn],n,k;

int gcd(int x,int y){
    if (x%y==0) return y; else return gcd(y,x%y);
}

int main()
{
    cin>>n;
    for (int i=0;i<n;i++) scanf("%d",&a[i]); sort(a,a+n);
    k=a[0]; for (int i=1;i<n;i++) k=gcd(k,a[i]);
    if (a[0]!=k){
        cout << -1 << endl;
        return 0;
    }
    cout << n*2 << endl;
    for (int i=0;i<n;i++) cout << a[i] << ' ' << k << ' ';
    cout << endl;
    return 0;
}