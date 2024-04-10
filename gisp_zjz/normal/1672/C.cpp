#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=1e6+10;
const int M=998244353;
int _,n,a[maxn],l,r;
int main(){
    cin >> _;
    while (_--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        l=-1; r=-1; 
        for (int i=2;i<=n;i++) if (a[i]==a[i-1]) r=i;
        for (int i=n-1;i>=1;i--) if (a[i]==a[i+1]) l=i;
        if (l==-1){puts("0");continue;}
        int len=r-l+1;
        if (len<=3) printf("%d\n",len-2); else printf("%d\n",len-3);
    }
    return 0;
}