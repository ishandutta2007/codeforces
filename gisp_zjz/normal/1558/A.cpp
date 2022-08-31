#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
const int maxn=1e5+10;
int _,a,b;
int main(){
    cin >> _;
    while (_--){
        cin >> a >> b;
        if (a>b) swap(a,b);
        int s=a+b;
        int l=s/2-a,r=s-l;
        if (s&1){
            printf("%d\n",r-l+1);
            for (int i=l;i<=r;i++) printf("%d ",i);puts("");
        } else {
            printf("%d\n",(r-l)/2+1);
            for (int i=l;i<=r;i+=2) printf("%d ",i);puts("");
        }
    }
}