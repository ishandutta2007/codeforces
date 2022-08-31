#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
const int maxn=5005;
int n,m,sc[maxn];
int E=10000;
int P=100000000;
int main(){
    cin >> n >> m;
    for (int i=1;i<=n;i++) sc[i]=sc[i-1]+(i-1)/2;
    if (sc[n]<m){
        puts("-1");
        return 0;
    }
    if (m==0){
        for (int i=1;i<=n;i++) cout << P+i*E << ' '; cout << endl;
        return 0;
    }
    int p=1;
    while (sc[p]<m) ++p;
    for (int i=1;i<p;i++) cout << i << ' ';
    cout << p+2*(sc[p]-m) << ' ';
    for (int i=p+1;i<=n;i++) cout << P+i*E << ' '; cout << endl;
    return 0;
}