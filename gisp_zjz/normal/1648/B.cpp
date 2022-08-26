#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int maxn=2e6+10;
bool f[maxn];
int cnt[maxn],_,n,c;
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d%d",&n,&c);
        for (int i=1;i<=c*2;i++) cnt[i]=f[i]=0;
        while (n--){
            int x; scanf("%d",&x);
            cnt[x]++; f[x]=1;
        }
        for (int i=2;i<=c*2;i++) cnt[i]+=cnt[i-1];
        bool ok=1;
        for (int i=1;i<=c;i++) if (!f[i]){
            for (int j=1;j*i<=c;j++) if (f[j]){
                if (cnt[i*j+j-1]-cnt[i*j-1]>0) ok=0;
            }
        }
        if (ok) puts("Yes"); else puts("No");
    }
    return 0;
}