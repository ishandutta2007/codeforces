#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int maxn=5e5+10;
const int M=998244353;
int _,n,a[15],p3[15];
int main(){
    cin >> _;
    p3[0]=1; for (int i=1;i<=10;i++) p3[i]=p3[i-1]*3;
    while (_--){
        cin >> n;
        for (int i=0;i<n;i++) cin >> a[i];
        bool flag=0;
        for (int i=1;i<p3[n];i++){
            int r=0,tmp=i;
            for (int j=0;j<n;j++){
                if (tmp%3==1) r-=a[j];
                else if (tmp%3==2) r+=a[j];
                tmp/=3;
            }
            if (!r) flag=1;
        }
        if (flag) puts("YES"); else puts("NO");
    }
}