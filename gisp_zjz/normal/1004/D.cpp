#include<bits/stdc++.h>
#define maxn 1234567

using namespace std;
int c[maxn],b[maxn],n,r,s,p;

bool check(int n,int m){
    s=n+m-p-r;
    if (r>n||s>m||s<1) return false;
    for (int i=0;i<=p;i++) b[i]=0;
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) b[abs(r-i)+abs(s-j)]++;
    for (int i=0;i<=p;i++) if (c[i]!=b[i]) return false;
    cout << n << ' ' << m << endl;
    cout << r << ' ' << s << endl;
    return true;
}

int main(){
    cin >> n;
    for (int i=0;i<n;i++){
        scanf("%d",&r);
        p=max(p,r); c[r]++;
    }
    for (int i=n;i;i--) if (c[i]!=i*4) r=i;
    for (int i=1;i*i<=n;i++) if (n%i==0){
        if (check(i,n/i)) return 0;
        if (check(n/i,i)) return 0;
    }
    cout << -1 << endl;
}