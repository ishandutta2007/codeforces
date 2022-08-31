#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
const int maxn=1e6+10;
typedef pair<string,int>pi;
string s;
pi a[maxn];
int n,m;
int main(){
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> s;
        for (int j=1;j<m;j+=2) s[j]='A'+'Z'-s[j];
        a[i]=(pi){s,i};
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) printf("%d ",a[i].S); puts("");
    return 0;
}