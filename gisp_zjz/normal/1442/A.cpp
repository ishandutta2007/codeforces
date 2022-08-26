#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
const int maxn=1e6+100;
int _,n,a[maxn],b[maxn],c[maxn];
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        bool flag=0;
        b[1]=a[1]; c[1]=0;
        for (int i=2;i<=n;i++){
            if (a[i]<c[i-1]) {flag=1;break;}
            c[i]=c[i-1]; b[i]=a[i]-c[i];
            if (b[i]>b[i-1]){
                int offset=b[i]-b[i-1];
                b[i]-=offset;
                c[i]+=offset;
            }
        }
        if (flag)puts("NO"); else  puts("YES");
    }
}